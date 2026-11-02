#pragma once
#include <iostream>
#include <string>

class Estudiante {
private:
    std::string nombre;
    std::string codigo;

public:
    Estudiante(std::string nombre, std::string codigo)
        : nombre(nombre), codigo(codigo) {}

    void mostrarDatos() const {
        std::cout << "Estudiante: " << nombre << " (" << codigo << ")" << std::endl;
    }
};
