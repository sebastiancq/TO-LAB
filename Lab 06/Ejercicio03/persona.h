#pragma once

#include <iostream>
#include <string>
#include <utility>

class Persona
{
protected:
    std::string nombre;
    std::string codigo;

public:
    Persona(std::string nombre, std::string codigo)
        : nombre(std::move(nombre)), codigo(std::move(codigo)) {}
    virtual ~Persona() = default;

    const std::string& getNombre() const { return nombre; }
    const std::string& getCodigo() const { return codigo; }
    virtual void presentarse() const = 0;
    virtual Persona* clonar() const = 0;

    friend bool operator==(const Persona& a, const Persona& b)
    {
        return a.codigo == b.codigo;
    }

    friend std::ostream& operator<<(std::ostream& salida, const Persona& persona)
    {
        return salida << persona.nombre << " (" << persona.codigo << ")";
    }
};

inline bool esMismoCodigo(const std::string& a, const std::string& b)
{
    return a == b;
}
