
#include "VentanaRegistro.h"
#include "Estudiante.h"

#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QMessageBox>
#include <QFont>
#include <QDate>
#include <QDateEdit>

VentanaRegistro::VentanaRegistro(QWidget *parent)
    : QWidget(parent) {

    setWindowTitle("Registro de Estudiantes");
    resize(460, 440);

    edtNombre = new QLineEdit(this);
    edtCodigo = new QLineEdit(this);

    btnRegistrar = new QPushButton("Registrar", this);
    btnLimpiar = new QPushButton("Limpiar", this);

    lblResultado = new QLabel("(sin registros aun)", this);
    listaEstudiantes = new QListWidget(this);

    edtCodigo->setValidator(
        new QIntValidator(0, 999999, this)
    );

    cmbCarrera = new QComboBox(this);
    cmbCarrera->addItems({
        "Ingenieria de Sistemas",
        "Ingenieria Electronica",
        "Ingenieria Civil"
    });

    chkIngresante = new QCheckBox("Es ingresante", this);

    edtFecha = new QDateEdit(this);
    edtFecha->setCalendarPopup(true);
    edtFecha->setDate(QDate::currentDate());
    edtFecha->setDisplayFormat("dd/MM/yyyy");


    auto *form = new QFormLayout();

    form->addRow("Nombre:", edtNombre);
    form->addRow("Codigo:", edtCodigo);
    form->addRow("Carrera:", cmbCarrera);
    form->addRow("Fecha de matricula:", edtFecha);
    form->addRow("", chkIngresante);

    form->setSpacing(12);
    form->setLabelAlignment(Qt::AlignRight);

    btnRegistrar->setMinimumHeight(34);
    btnLimpiar->setMinimumHeight(34);

    auto *botones = new QHBoxLayout();
    botones->addWidget(btnRegistrar);
    botones->addWidget(btnLimpiar);

    auto *titulo = new QLabel("Registro de Estudiantes", this);
    titulo->setAlignment(Qt::AlignCenter);

    QFont fuente = titulo->font();
    fuente.setPointSize(14);
    fuente.setBold(true);
    titulo->setFont(fuente);

    auto *layout = new QVBoxLayout(this);

    layout->setContentsMargins(25, 20, 25, 20);
    layout->setSpacing(12);

    layout->addWidget(titulo);
    layout->addLayout(form);
    layout->addLayout(botones);
    layout->addWidget(lblResultado);
    layout->addWidget(new QLabel("Historial de estudiantes:", this));
    layout->addWidget(listaEstudiantes);

    connect(btnRegistrar, &QPushButton::clicked,
            this, &VentanaRegistro::registrarEstudiante);

    connect(btnLimpiar, &QPushButton::clicked,
            this, &VentanaRegistro::limpiarFormulario);

    connect(edtCodigo, &QLineEdit::returnPressed,
            this, &VentanaRegistro::registrarEstudiante);
}

void VentanaRegistro::registrarEstudiante() {
    QString nombre = edtNombre->text();
    QString codigo = edtCodigo->text();

    if (nombre.isEmpty() || codigo.isEmpty()) {
        lblResultado->setStyleSheet("color: red;");
        lblResultado->setText("Complete ambos campos.");

        QMessageBox::warning(
            this,
            "Datos incompletos",
            "Complete nombre y codigo."
        );
        return;
    }

    Estudiante e(
        nombre.toStdString(),
        codigo.toStdString()
    );

    QString carrera = cmbCarrera->currentText();
    bool ingresante = chkIngresante->isChecked();
    QString fecha = edtFecha->date().toString("dd/MM/yyyy");

    listaEstudiantes->addItem(
        QString("%1  %2  %3  %4  %5")
            .arg(
                nombre,
                codigo,
                carrera,
                fecha,
                ingresante ? "Ingresante" : "No ingresante"
            )
    );


    lblResultado->setStyleSheet("");
    lblResultado->setText(
        QString("Estudiante registrado: %1 (%2)")
            .arg(nombre, codigo)
    );

    QMessageBox::information(
        this,
        "Registro exitoso",
        QString(
            "Nombre: %1\n"
            "Codigo: %2\n"
            "Carrera: %3\n"
            "Fecha de matricula: %4\n"
            "Ingresante: %5"
        ).arg(
            nombre,
            codigo,
            carrera,
            fecha,
            ingresante ? "Si" : "No"
        )
    );

    edtNombre->clear();
    edtCodigo->clear();
    chkIngresante->setChecked(false);
}

void VentanaRegistro::limpiarFormulario() {
    edtNombre->clear();
    edtCodigo->clear();

    lblResultado->setStyleSheet("");
    lblResultado->setText("(sin registros aun)");
}
