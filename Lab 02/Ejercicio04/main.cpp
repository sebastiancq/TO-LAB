#include <iostream>
#include <vector>
#include <memory>
#include "Estudiante.h"

int main() {
    std::vector<std::unique_ptr<Estudiante>> listaEstudiantes;

    listaEstudiantes.push_back(std::make_unique<Estudiante>("Juan Perez", "20260001"));
    listaEstudiantes.push_back(std::make_unique<Estudiante>("Maria Lopez", "20260002"));
    listaEstudiantes.push_back(std::make_unique<Estudiante>("Carlos Ruiz", "20260003"));

    std::cout << "\nLISTA DE ESTUDIANTES" << std::endl;
    for(size_t i = 0; i < listaEstudiantes.size(); i++) {
        listaEstudiantes[i]->mostrarDatos();
    }

    std::cout << "\nFIN DEL PROGRAMA" << std::endl;
    
    return 0; // Al salir, los destructores se llaman automáticamente
}