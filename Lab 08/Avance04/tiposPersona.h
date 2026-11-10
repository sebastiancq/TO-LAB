#pragma once

#include "PersonaFactory.h"
#include "estudiante.h"
#include "docente.h"

// Unico lugar del sistema que conoce las subclases concretas de Persona.
// Para ofrecer Administrativo en el formulario bastaria con registrarlo aqui.
inline void registrarTiposDePersona()
{
    PersonaFactory::registrarTipo("Estudiante",
        [](const std::string& nombre, const std::string& codigo, const std::string& carrera) -> Persona*
        { return new Estudiante(nombre, codigo, carrera); });

    PersonaFactory::registrarTipo("Docente",
        [](const std::string& nombre, const std::string& codigo, const std::string& departamento) -> Persona*
        { return new Docente(nombre, codigo, departamento); });
}
