
#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QCheckBox>
#include <QDateEdit>
#include <QTableWidget>

class VentanaRegistro : public QWidget {
    Q_OBJECT

public:
    explicit VentanaRegistro(QWidget *parent = nullptr);

private slots:
    void registrarEstudiante();
    void limpiarFormulario();
    void mostrarDetalle(int fila, int columna);

private:
    QLineEdit *edtNombre;
    QLineEdit *edtCodigo;

    QPushButton *btnRegistrar;
    QPushButton *btnLimpiar;

    QComboBox *cmbCarrera;
    QCheckBox *chkIngresante;
    QDateEdit *edtFecha;

    QTableWidget *tablaEstudiantes;
};
