#include <QApplication>
#include "tiposPersona.h"
#include "SistemaMatricula.h"
#include "VistaRegistro.h"
#include "ControladorRegistro.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    registrarTiposDePersona();

    SistemaMatricula modelo;
    VistaRegistro vista;
    ControladorRegistro controlador(&vista, &modelo);

    // Cada estudiante registrado pasa a la lista de matricula y cada
    // matricula confirmada se agrega a la tabla.
    modelo.agregarObservadorRegistro(
        [&vista](const Persona& p)
        {
            if (dynamic_cast<const Estudiante*>(&p))
                vista.agregarEstudiante(QString::fromStdString(p.getCodigo()),
                                        QString::fromStdString(p.getNombre()));
        });
    modelo.agregarObservador(
        [&vista](const Matricula& m)
        {
            vista.agregarFilaMatricula(
                QString::fromStdString(m.fecha),
                QString::fromStdString(m.estudiante->getCodigo()),
                QString::fromStdString(m.estudiante->getNombre()),
                QString::fromStdString(m.curso->getNombre()));
        });

    const Curso& to = modelo.registrarCurso(
        std::make_unique<Curso>("TO-401", "Tecnologia de Objetos", "301", 2));
    const Curso& ada = modelo.registrarCurso(std::make_unique<Curso>(
        "ADA-402", "Analisis y Diseno de Algoritmos", "205", 30));
    for (const Curso* c : { &to, &ada })
        vista.agregarCurso(QString::fromStdString(c->getCodigo()),
                           QString::fromStdString(c->getNombre()));

    vista.show();
    return app.exec();
}
