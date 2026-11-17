#pragma once

#include "PersonaFactory.h"
#include "estudiante.h"
#include "docente.h"

// Registra en la fabrica cada subclase concreta de Persona con su creador.
inline void registrarTiposDePersona()
{
    PersonaFactory::registrarTipo(
        "Estudiante",
        [](const std::string& nombre, const std::string& codigo,
           const std::string& carrera) -> std::unique_ptr<Persona>
        { return std::make_unique<Estudiante>(nombre, codigo, carrera); });

    PersonaFactory::registrarTipo(
        "Docente",
        [](const std::string& nombre, const std::string& codigo,
           const std::string& departamento) -> std::unique_ptr<Persona>
        { return std::make_unique<Docente>(nombre, codigo, departamento); });
}
