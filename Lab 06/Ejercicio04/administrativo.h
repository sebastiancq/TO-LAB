#pragma once

#include "persona.h"

class Administrativo : public Persona
{
private:
    std::string area;

public:
    Administrativo(std::string nombre, std::string codigo, std::string area)
        : Persona(std::move(nombre), std::move(codigo)), area(std::move(area)) {}

    const std::string& getArea() const { return area; }

    void presentarse() const override
    {
        std::cout << "Administrativo: " << *this << ", area: " << area << '\n';
    }

    Administrativo* clonar() const override
    {
        return new Administrativo(*this);
    }
};
