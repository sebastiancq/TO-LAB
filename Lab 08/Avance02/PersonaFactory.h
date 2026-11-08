#pragma once

#include "estudiante.h"
#include "docente.h"
#include <stdexcept>

enum class TipoPersona { ESTUDIANTE, DOCENTE };

// Unico lugar del sistema que conoce las subclases concretas de Persona.
// Quien recibe el puntero se encarga de liberarlo con delete.
class PersonaFactory
{
public:
    static Persona* crearPersona(TipoPersona tipo, const std::string& nombre,
                                 const std::string& codigo, const std::string& extra)
    {
        switch (tipo)
        {
        case TipoPersona::ESTUDIANTE:
            return new Estudiante(nombre, codigo, extra);
        case TipoPersona::DOCENTE:
            return new Docente(nombre, codigo, extra);
        }
        throw std::invalid_argument("Tipo de persona no reconocido");
    }

    // El formulario entrega como texto el tipo elegido en la lista desplegable.
    static TipoPersona tipoDesdeTexto(const std::string& texto)
    {
        if (texto == "Estudiante")
            return TipoPersona::ESTUDIANTE;
        if (texto == "Docente")
            return TipoPersona::DOCENTE;
        throw std::invalid_argument("Tipo de persona no reconocido: " + texto);
    }
};
