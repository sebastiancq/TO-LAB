#pragma once

#include "persona.h"

class Estudiante : public Persona
{
private:
    std::string carrera;

public:
    Estudiante(std::string nombre, std::string codigo, std::string carrera)
        : Persona(std::move(nombre), std::move(codigo)), carrera(std::move(carrera)) {}

    const std::string& getCarrera() const { return carrera; }

    void presentarse() const override
    {
        std::cout << "Estudiante: " << *this << ", carrera: " << carrera << '\n';
    }

    Estudiante* clonar() const override
    {
        return new Estudiante(*this);
    }
};
