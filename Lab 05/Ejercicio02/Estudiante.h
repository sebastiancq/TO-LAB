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

private:
    string nombre;
    string codigo;
    int orden;
    static int contador;
};
