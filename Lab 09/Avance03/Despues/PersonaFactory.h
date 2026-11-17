#pragma once

#include "persona.h"
#include <functional>
#include <map>
#include <memory>
#include <stdexcept>

// Recibe nombre, codigo y el dato propio de cada tipo, como la carrera o el
// departamento.
using CreadorPersona = std::function<std::unique_ptr<Persona>(
    const std::string&, const std::string&, const std::string&)>;

// Crea personas a partir del tipo elegido en la lista desplegable del
// formulario. Cada tipo se registra con su creador, asi que agregar uno nuevo
// no modifica esta clase. La persona creada se devuelve en un unique_ptr.
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

    static std::unique_ptr<Persona> crearPersona(const std::string& tipo,
                                                 const std::string& nombre,
                                                 const std::string& codigo,
                                                 const std::string& extra)
    {
        auto it = creadores().find(tipo);
        if (it == creadores().end())
            throw std::invalid_argument("Tipo de persona no reconocido: " +
                                        tipo);
        return it->second(nombre, codigo, extra);
    }
};
