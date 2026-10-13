#pragma once

#include <QDialog>
#include "Estudiante.h"

class DialogoDetalle : public QDialog {
public:
    explicit DialogoDetalle(
        const Estudiante &estudiante,
        QWidget *parent = nullptr
    );
};
