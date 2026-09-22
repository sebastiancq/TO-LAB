#include <iostream>
#include "Curso.h"

int main() {
    Curso curso1("Programacion en C++", 30);

    std::cout << "Nombre del curso: " << curso1.getNombre() << std::endl;
    std::cout << "Capacidad del curso: " << curso1.getCapacidad() << " estudiantes." << std::endl;

    curso1.setNombre("Estructuras de Datos");
    curso1.setCapacidad(25);

    std::cout << "Nombre actualizado del curso: " << curso1.getNombre() << std::endl;
    std::cout << "Capacidad actualizada del curso: " << curso1.getCapacidad() << " estudiantes." << std::endl;

    return 0;
}