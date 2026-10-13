
#pragma once

#include <string>
#include <iostream>

using namespace std;

class Estudiante {
public:
    Estudiante(string nombre, string codigo)
        : nombre(nombre), codigo(codigo) {
        contador++;
        orden = contador;

        cout << "Estudiante creado #" << orden
                  << ": " << nombre
                  << " (" << codigo << ")" << endl;
    }

    const string& getNombre() const {
        return nombre;
    }

    const string& getCodigo() const {
        return codigo;
    }

private:
    string nombre;
    string codigo;
    int orden;
    static int contador;
};
