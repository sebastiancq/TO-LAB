#include "VentanaRegistro.h"
#include "tiposPersona.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QRegularExpressionValidator>
#include <QVBoxLayout>

VentanaRegistro::VentanaRegistro(QWidget* parent) : QWidget(parent)
{
    setWindowTitle("Registro y matrícula");
    resize(720, 560);

    registrarTiposDePersona();
    cursos.push_back(
        std::make_unique<Curso>("TO-401", "Tecnologia de Objetos", "301", 2));
    cursos.push_back(std::make_unique<Curso>(
        "ADA-402", "Analisis y Diseno de Algoritmos", "205", 30));

    cmbTipo = new QComboBox(this);
    cmbTipo->setObjectName("cmbTipo");
    cmbTipo->addItems({ "Estudiante", "Docente" });
    edtNombre = new QLineEdit(this);
    edtNombre->setObjectName("edtNombre");
    edtCodigo = new QLineEdit(this);
    edtCodigo->setObjectName("edtCodigo");
    edtCodigo->setValidator(new QRegularExpressionValidator(
        QRegularExpression("[A-Z0-9-]{1,10}"), this));
    lblDato = new QLabel("Carrera:", this);
    edtDato = new QLineEdit(this);
    edtDato->setObjectName("edtDato");
    btnRegistrar = new QPushButton("Registrar persona", this);
    btnRegistrar->setObjectName("btnRegistrar");

    auto* formPersona = new QFormLayout();
    formPersona->addRow("Tipo:", cmbTipo);
    formPersona->addRow("Nombre:", edtNombre);
    formPersona->addRow("Código:", edtCodigo);
    formPersona->addRow(lblDato, edtDato);
    formPersona->addRow("", btnRegistrar);
    auto* grupoPersona = new QGroupBox("Registrar persona", this);
    grupoPersona->setLayout(formPersona);

    cmbEstudiante = new QComboBox(this);
    cmbEstudiante->setObjectName("cmbEstudiante");
    cmbCurso = new QComboBox(this);
    cmbCurso->setObjectName("cmbCurso");
    for (const auto& c : cursos)
        cmbCurso->addItem(QString::fromStdString(c->getNombre()),
                          QString::fromStdString(c->getCodigo()));
    edtFecha = new QDateEdit(QDate(2026, 11, 13), this);
    edtFecha->setObjectName("edtFecha");
    edtFecha->setCalendarPopup(true);
    edtFecha->setDisplayFormat("dd/MM/yyyy");
    btnMatricular = new QPushButton("Matricular", this);
    btnMatricular->setObjectName("btnMatricular");

    auto* formMatricula = new QFormLayout();
    formMatricula->addRow("Estudiante:", cmbEstudiante);
    formMatricula->addRow("Curso:", cmbCurso);
    formMatricula->addRow("Fecha:", edtFecha);
    formMatricula->addRow("", btnMatricular);
    auto* grupoMatricula = new QGroupBox("Matricular", this);
    grupoMatricula->setLayout(formMatricula);

    auto* formularios = new QHBoxLayout();
    formularios->addWidget(grupoPersona);
    formularios->addWidget(grupoMatricula);

    tablaMatriculas = new QTableWidget(0, 4, this);
    tablaMatriculas->setHorizontalHeaderLabels(
        { "Fecha", "Código", "Estudiante", "Curso" });
    tablaMatriculas->horizontalHeader()->setSectionResizeMode(
        QHeaderView::Stretch);
    tablaMatriculas->setEditTriggers(QAbstractItemView::NoEditTriggers);
    lblResultado = new QLabel("Sin registros aún", this);

    auto* layout = new QVBoxLayout(this);
    layout->addLayout(formularios);
    layout->addWidget(new QLabel("Matrículas confirmadas:", this));
    layout->addWidget(tablaMatriculas);
    layout->addWidget(lblResultado);

    connect(btnRegistrar, &QPushButton::clicked, this,
            &VentanaRegistro::registrarPersona);
    connect(btnMatricular, &QPushButton::clicked, this,
            &VentanaRegistro::matricular);
    connect(cmbTipo, &QComboBox::currentTextChanged, this,
            &VentanaRegistro::actualizarEtiquetaDato);
}

void VentanaRegistro::actualizarEtiquetaDato()
{
    lblDato->setText(cmbTipo->currentText() == "Estudiante" ? "Carrera:"
                                                            : "Departamento:");
}

// Valida los campos, crea la persona con la fabrica, revisa duplicados, la
// guarda y actualiza los widgets.
void VentanaRegistro::registrarPersona()
{
    QString nombre = edtNombre->text().trimmed();
    QString codigo = edtCodigo->text().trimmed();
    QString dato = edtDato->text().trimmed();
    if (nombre.isEmpty() || codigo.isEmpty() || dato.isEmpty())
    {
        QMessageBox::warning(this, "Datos incompletos",
                             "Complete todos los campos de la persona.");
        return;
    }

    for (const auto& p : personas)
    {
        if (p->getCodigo() == codigo.toStdString())
        {
            QMessageBox::warning(this, "Código repetido",
                                 "Ya existe una persona con el código " +
                                     codigo + ".");
            return;
        }
    }

    std::unique_ptr<Persona> nueva = PersonaFactory::crearPersona(
        cmbTipo->currentText().toStdString(), nombre.toStdString(),
        codigo.toStdString(), dato.toStdString());
    if (dynamic_cast<Estudiante*>(nueva.get()))
        cmbEstudiante->addItem(nombre + " (" + codigo + ")", codigo);

    personas.push_back(std::move(nueva));

    lblResultado->setText(cmbTipo->currentText() + " registrado: " + nombre +
                          " (" + codigo + ")");
    edtNombre->clear();
    edtCodigo->clear();
    edtDato->clear();
    edtNombre->setFocus();
}

void VentanaRegistro::matricular()
{
    if (cmbEstudiante->count() == 0)
    {
        QMessageBox::warning(this, "Sin estudiantes",
                             "Registre al menos un estudiante.");
        return;
    }

    std::string codigoEstudiante =
        cmbEstudiante->currentData().toString().toStdString();
    std::string codigoCurso = cmbCurso->currentData().toString().toStdString();

    Estudiante* estudiante = nullptr;
    for (const auto& p : personas)
        if (p->getCodigo() == codigoEstudiante)
            estudiante = dynamic_cast<Estudiante*>(p.get());
    Curso* curso = nullptr;
    for (const auto& c : cursos)
        if (c->getCodigo() == codigoCurso)
            curso = c.get();

    if (!curso->ocuparCupo())
    {
        QMessageBox::warning(this, "Sin cupo",
                             QString::fromStdString(curso->getNombre()) +
                                 " ya no tiene cupos.");
        return;
    }

    QString fecha = edtFecha->date().toString("dd/MM/yyyy");
    int fila = tablaMatriculas->rowCount();
    tablaMatriculas->insertRow(fila);
    tablaMatriculas->setItem(fila, 0, new QTableWidgetItem(fecha));
    tablaMatriculas->setItem(
        fila, 1,
        new QTableWidgetItem(QString::fromStdString(estudiante->getCodigo())));
    tablaMatriculas->setItem(
        fila, 2,
        new QTableWidgetItem(QString::fromStdString(estudiante->getNombre())));
    tablaMatriculas->setItem(
        fila, 3,
        new QTableWidgetItem(QString::fromStdString(curso->getNombre())));

    lblResultado->setText(
        QString("Aula %1: %2 de %3 cupos ocupados")
            .arg(QString::fromStdString(curso->getAula().getCodigo()))
            .arg(curso->getInscritos())
            .arg(curso->getAula().getCapacidad()));
}
