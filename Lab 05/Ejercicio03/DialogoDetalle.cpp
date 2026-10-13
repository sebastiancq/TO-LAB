
#include "DialogoDetalle.h"

#include <QLabel>
#include <QFormLayout>
#include <QString>

DialogoDetalle::DialogoDetalle(
    const Estudiante &estudiante,
    QWidget *parent
) : QDialog(parent) {

    setWindowTitle("Detalle del estudiante");
    resize(350, 150);

    auto *layout = new QFormLayout(this);

    auto *lblNombre = new QLabel(
        QString::fromStdString(estudiante.getNombre()), this
    );

    auto *lblCodigo = new QLabel(
        QString::fromStdString(estudiante.getCodigo()), this
    );

    layout->addRow("Nombre:", lblNombre);
    layout->addRow("Codigo:", lblCodigo);
}
