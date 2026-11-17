#include "VistaRegistro.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QRegularExpressionValidator>
#include <QVBoxLayout>

VistaRegistro::VistaRegistro(QWidget* parent) : QWidget(parent)
{
    setWindowTitle("Registro y matrícula");
    resize(720, 560);

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

    // Cada clic se reemite como una senal de la vista.
    connect(btnRegistrar, &QPushButton::clicked, this,
            &VistaRegistro::solicitarRegistro);
    connect(btnMatricular, &QPushButton::clicked, this,
            &VistaRegistro::solicitarMatricula);
    connect(cmbTipo, &QComboBox::currentTextChanged, this,
            &VistaRegistro::actualizarEtiquetaDato);
}

// Muestra Carrera o Departamento segun el tipo de persona elegido.
void VistaRegistro::actualizarEtiquetaDato(const QString& tipo)
{
    lblDato->setText(tipo == "Estudiante" ? "Carrera:" : "Departamento:");
}

void VistaRegistro::agregarCurso(const QString& codigo, const QString& nombre)
{
    cmbCurso->addItem(nombre, codigo);
}

void VistaRegistro::agregarEstudiante(const QString& codigo,
                                      const QString& nombre)
{
    cmbEstudiante->addItem(nombre + " (" + codigo + ")", codigo);
}

void VistaRegistro::agregarFilaMatricula(const QString& fecha,
                                         const QString& codigo,
                                         const QString& estudiante,
                                         const QString& curso)
{
    int fila = tablaMatriculas->rowCount();
    tablaMatriculas->insertRow(fila);
    tablaMatriculas->setItem(fila, 0, new QTableWidgetItem(fecha));
    tablaMatriculas->setItem(fila, 1, new QTableWidgetItem(codigo));
    tablaMatriculas->setItem(fila, 2, new QTableWidgetItem(estudiante));
    tablaMatriculas->setItem(fila, 3, new QTableWidgetItem(curso));
}

void VistaRegistro::mostrarResultado(const QString& texto)
{
    lblResultado->setText(texto);
}

void VistaRegistro::mostrarError(const QString& titulo, const QString& texto)
{
    QMessageBox::warning(this, titulo, texto);
}

void VistaRegistro::limpiarCamposPersona()
{
    edtNombre->clear();
    edtCodigo->clear();
    edtDato->clear();
    edtNombre->setFocus();
}
