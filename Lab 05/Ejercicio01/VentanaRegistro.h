
#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QListWidget>
#include <QDateEdit>
class VentanaRegistro : public QWidget {
    Q_OBJECT

public:
    explicit VentanaRegistro(QWidget *parent = nullptr);

private slots:
    void registrarEstudiante();
    void limpiarFormulario();

private:
    QDateEdit *edtFecha;
    QLineEdit *edtNombre;
    QLineEdit *edtCodigo;

    QPushButton *btnRegistrar;
    QPushButton *btnLimpiar;
    QLabel *lblResultado;
    QListWidget *listaEstudiantes;

    QComboBox *cmbCarrera;
    QCheckBox *chkIngresante;
};
