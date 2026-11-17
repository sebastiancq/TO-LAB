#pragma once

#include "persona.h"
#include "curso.h"
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QDateEdit>
#include <QTableWidget>
#include <QLabel>
#include <memory>
#include <vector>

// Formulario de registro y matricula: arma los widgets, valida los datos,
// crea las personas, guarda las listas y decide que mostrar.
class VentanaRegistro : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaRegistro(QWidget* parent = nullptr);

private slots:
    void registrarPersona();
    void matricular();
    void actualizarEtiquetaDato();

private:
    QComboBox* cmbTipo;
    QLineEdit* edtNombre;
    QLineEdit* edtCodigo;
    QLabel* lblDato;
    QLineEdit* edtDato;
    QPushButton* btnRegistrar;

    QComboBox* cmbEstudiante;
    QComboBox* cmbCurso;
    QDateEdit* edtFecha;
    QPushButton* btnMatricular;

    QTableWidget* tablaMatriculas;
    QLabel* lblResultado;

    // Personas y cursos registrados.
    std::vector<std::unique_ptr<Persona>> personas;
    std::vector<std::unique_ptr<Curso>> cursos;
};
