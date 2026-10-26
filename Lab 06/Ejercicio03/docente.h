#pragma once

#include "persona.h"

class Docente : public Persona
{
private:
    std::string departamento;

public:
    Docente(std::string nombre, std::string codigo, std::string departamento)
        : Persona(std::move(nombre), std::move(codigo)), departamento(std::move(departamento)) {}

    const std::string& getDepartamento() const { return departamento; }

    void presentarse() const override
    {
        std::cout << "Docente: " << *this << ", departamento: " << departamento << '\n';
    }

    Docente* clonar() const override
    {
        return new Docente(*this);
    }
};
