#pragma once

#include "VistaRegistro.h"
#include "SistemaMatricula.h"
#include <QObject>

// Controlador: reacciona a las senales de la vista, valida la entrada,
// pide al modelo que registre o matricule y decide que mensaje mostrar.
class ControladorRegistro : public QObject
{
    Q_OBJECT

public:
    ControladorRegistro(VistaRegistro* vista, SistemaMatricula* modelo,
                        QObject* parent = nullptr);

private slots:
    void onSolicitarRegistro();
    void onSolicitarMatricula();

private:
    VistaRegistro* vista;
    SistemaMatricula* modelo;
};
