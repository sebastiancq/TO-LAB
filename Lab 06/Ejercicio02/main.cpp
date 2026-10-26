#include "estudiante.h"
#include "docente.h"
#include <stdexcept>

void verificar(bool condicion, const char* mensaje)
{
    if (!condicion)
        throw std::runtime_error(mensaje);
}

int main()
{
    const Estudiante estudiante("Ana Torres", "20261234", "Ingenieria de Sistemas");
    const Docente docente("Roxana Limache", "D-0456", "Sistemas");

    estudiante.presentarse();
    docente.presentarse();
    std::cout << "Carrera: " << estudiante.getCarrera() << '\n';
    std::cout << "Departamento: " << docente.getDepartamento() << '\n';

    Estudiante* copiaEstudiante = estudiante.clonar();
    Docente* copiaDocente = docente.clonar();
    std::cout << "Clon del estudiante: " << *copiaEstudiante << '\n';
    std::cout << "Clon del docente: " << *copiaDocente << '\n';
    verificar(copiaEstudiante != &estudiante && *copiaEstudiante == estudiante,
              "El clon de Estudiante debe ser independiente y conservar su codigo");
    verificar(copiaDocente != &docente && *copiaDocente == docente,
              "El clon de Docente debe ser independiente y conservar su codigo");
    verificar(copiaEstudiante->getCarrera() == estudiante.getCarrera(), "Carrera no conservada");
    verificar(copiaDocente->getDepartamento() == docente.getDepartamento(), "Departamento no conservado");

    delete copiaEstudiante;
    delete copiaDocente;
}
