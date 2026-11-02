#include "Estudiante.h"
#include "Docente.h"
#include "Cola.h"

int main() {
    Cola<Estudiante> turnosEstudiantes;
    turnosEstudiantes.encolar(Estudiante("Ana Torres", "20261234"));
    turnosEstudiantes.encolar(Estudiante("Carlos Vega", "20261111"));
    turnosEstudiantes.encolar(Estudiante("Luis Perez", "20265678"));

    Cola<Docente> turnosDocentes;
    turnosDocentes.encolar(Docente("Roxana Limache", "D-0456"));
    turnosDocentes.encolar(Docente("Maria Lopez", "D-0789"));

    std::cout << "Atencion de estudiantes" << std::endl;
    std::cout << "Estudiantes en cola: " << turnosEstudiantes.tamanio() << std::endl;
    while (!turnosEstudiantes.estaVacia()) {
        turnosEstudiantes.desencolar().mostrarDatos();
    }

    std::cout << std::endl;

    std::cout << "Atencion de docentes" << std::endl;
    std::cout << "Docentes en cola: " << turnosDocentes.tamanio() << std::endl;
    std::cout << "Siguiente: ";
    turnosDocentes.frente().presentarse();
    while (!turnosDocentes.estaVacia()) {
        turnosDocentes.desencolar().presentarse();
    }

    return 0;
}
