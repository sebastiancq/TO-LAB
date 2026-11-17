#include "ControladorRegistro.h"
#include "PersonaFactory.h"

ControladorRegistro::ControladorRegistro(VistaRegistro* vista,
                                         SistemaMatricula* modelo,
                                         QObject* parent)
    : QObject(parent), vista(vista), modelo(modelo)
{
    connect(vista, &VistaRegistro::solicitarRegistro, this,
            &ControladorRegistro::onSolicitarRegistro);
    connect(vista, &VistaRegistro::solicitarMatricula, this,
            &ControladorRegistro::onSolicitarMatricula);
}

void ControladorRegistro::onSolicitarRegistro()
{
    QString tipo = vista->tipoElegido();
    QString nombre = vista->nombreIngresado();
    QString codigo = vista->codigoIngresado();
    QString dato = vista->datoIngresado();
    if (nombre.isEmpty() || codigo.isEmpty() || dato.isEmpty())
    {
        vista->mostrarError("Datos incompletos",
                            "Complete todos los campos de la persona.");
        return;
    }

    std::unique_ptr<Persona> nueva =
        PersonaFactory::crearPersona(tipo.toStdString(), nombre.toStdString(),
                                     codigo.toStdString(), dato.toStdString());
    if (!modelo->registrarPersona(std::move(nueva)))
    {
        vista->mostrarError("Código repetido",
                            "Ya existe una persona con el código " + codigo +
                                ".");
        return;
    }
    vista->mostrarResultado(tipo + " registrado: " + nombre + " (" + codigo +
                            ")");
    vista->limpiarCamposPersona();
}

void ControladorRegistro::onSolicitarMatricula()
{
    auto* estudiante = dynamic_cast<Estudiante*>(
        modelo->buscarPersona(vista->estudianteElegido().toStdString()));
    Curso* curso = modelo->buscarCurso(vista->cursoElegido().toStdString());
    if (estudiante == nullptr || curso == nullptr)
    {
        vista->mostrarError("Datos incompletos",
                            "Elija un estudiante y un curso.");
        return;
    }

    if (!modelo->matricular(estudiante, curso,
                            vista->fechaElegida().toStdString()))
    {
        QString nombreCurso = QString::fromStdString(curso->getNombre());
        if (modelo->estaMatriculado(estudiante, curso))
            vista->mostrarError(
                "Matrícula repetida",
                QString::fromStdString(estudiante->getNombre()) +
                    " ya tiene matrícula en " + nombreCurso + ".");
        else
            vista->mostrarError("Sin cupo",
                                nombreCurso + " ya no tiene cupos.");
        return;
    }
    vista->mostrarResultado(
        QString("Aula %1: %2 de %3 cupos ocupados")
            .arg(QString::fromStdString(curso->getAula().getCodigo()))
            .arg(curso->getInscritos())
            .arg(curso->getAula().getCapacidad()));
}
