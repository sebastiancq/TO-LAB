#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QDateEdit>
#include <QTableWidget>
#include <QLabel>

// Vista del formulario: arma los widgets, entrega los textos ingresados y
// avisa con senales lo que pide el usuario.
class VistaRegistro : public QWidget
{
    Q_OBJECT

public:
    explicit VistaRegistro(QWidget* parent = nullptr);

    QString tipoElegido() const { return cmbTipo->currentText(); }
    QString nombreIngresado() const { return edtNombre->text().trimmed(); }
    QString codigoIngresado() const { return edtCodigo->text().trimmed(); }
    QString datoIngresado() const { return edtDato->text().trimmed(); }
    QString estudianteElegido() const
    {
        return cmbEstudiante->currentData().toString();
    }
    QString cursoElegido() const { return cmbCurso->currentData().toString(); }
    QString fechaElegida() const
    {
        return edtFecha->date().toString("dd/MM/yyyy");
    }

    void agregarCurso(const QString& codigo, const QString& nombre);
    void agregarEstudiante(const QString& codigo, const QString& nombre);
    void agregarFilaMatricula(const QString& fecha, const QString& codigo,
                              const QString& estudiante, const QString& curso);
    void mostrarResultado(const QString& texto);
    void mostrarError(const QString& titulo, const QString& texto);
    void limpiarCamposPersona();

signals:
    void solicitarRegistro();
    void solicitarMatricula();

private slots:
    void actualizarEtiquetaDato(const QString& tipo);

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
};
