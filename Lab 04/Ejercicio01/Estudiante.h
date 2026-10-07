#pragma once
#include <string>
#include <iostream>

class Estudiante {
public:
    Estudiante(std::string nombre, std::string codigo)
        : nombre(nombre), codigo(codigo) {
        contador++;
        orden = contador;
        std::cout << "Estudiante creado #" << orden << ": "
                  << nombre << " (" << codigo << ")" << std::endl;
    }
private:
    std::string nombre;
    std::string codigo;
    int orden;
    static int contador;
};
