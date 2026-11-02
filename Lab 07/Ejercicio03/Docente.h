#pragma once
#include <iostream>
#include <string>

class Persona {
protected:
    std::string nombre;
    std::string codigo;

public:
    Persona(std::string nombre, std::string codigo)
        : nombre(nombre), codigo(codigo) {}
    virtual ~Persona() {}
    virtual void presentarse() const = 0;
};

class Docente : public Persona {
public:
    Docente(std::string nombre, std::string codigo)
        : Persona(nombre, codigo) {}

    void presentarse() const override {
        std::cout << "Soy el docente " << nombre << " (" << codigo << ")" << std::endl;
    }
};
