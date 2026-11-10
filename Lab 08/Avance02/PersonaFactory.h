#pragma once

#include "persona.h"
#include <functional>
#include <map>
#include <stdexcept>

// Recibe nombre, codigo y el dato propio de cada tipo, como la carrera o el departamento.
using CreadorPersona =
    std::function<Persona*(const std::string&, const std::string&, const std::string&)>;

// Crea personas a partir del tipo elegido en la lista desplegable del formulario.
// No conoce las subclases concretas: cada tipo se registra con su creador, por lo que
// agregar un tipo nuevo no obliga a modificar esta clase.
// Quien recibe el puntero se encarga de liberarlo con delete.
class PersonaFactory
{
private:
    static std::map<std::string, CreadorPersona>& creadores()
    {
        static std::map<std::string, CreadorPersona> tabla;
        return tabla;
    }

public:
    static void registrarTipo(const std::string& tipo, CreadorPersona creador)
    {
        creadores()[tipo] = creador;
    }

    static Persona* crearPersona(const std::string& tipo, const std::string& nombre,
                                 const std::string& codigo, const std::string& extra)
    {
        auto it = creadores().find(tipo);
        if (it == creadores().end())
            throw std::invalid_argument("Tipo de persona no reconocido: " + tipo);
        return it->second(nombre, codigo, extra);
    }
};
