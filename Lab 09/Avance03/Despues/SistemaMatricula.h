#pragma once

#include "estudiante.h"
#include "curso.h"
#include <functional>
#include <memory>
#include <vector>

struct Matricula
{
    const Estudiante* estudiante;
    const Curso* curso;
    std::string fecha;
};

// Modelo del sistema: guarda personas, cursos y matriculas, aplica sus reglas
// y avisa de cada cambio a sus observadores.
class SistemaMatricula
{
private:
    std::vector<std::unique_ptr<Persona>> personas;
    std::vector<std::unique_ptr<Curso>> cursos;
    std::vector<Matricula> matriculas;
    std::vector<std::function<void(const Persona&)>> observadoresRegistro;
    std::vector<std::function<void(const Matricula&)>> observadoresMatricula;

public:
    void agregarObservadorRegistro(
        std::function<void(const Persona&)> observador)
    {
        observadoresRegistro.push_back(observador);
    }

    void agregarObservador(std::function<void(const Matricula&)> observador)
    {
        observadoresMatricula.push_back(observador);
    }

    // Toma posesion de la persona solo si su codigo no esta registrado; si
    // esta repetido, el unique_ptr la libera al salir. La comparacion usa el
    // operator== amigo de Persona.
    bool registrarPersona(std::unique_ptr<Persona> persona)
    {
        for (const auto& p : personas)
            if (*p == *persona)
                return false;
        const Persona& registrada = *persona;
        personas.push_back(std::move(persona));
        for (auto& observador : observadoresRegistro)
            observador(registrada);
        return true;
    }

    // Devuelve el curso para que quien lo creo pueda mostrarlo sin buscarlo.
    Curso& registrarCurso(std::unique_ptr<Curso> curso)
    {
        cursos.push_back(std::move(curso));
        return *cursos.back();
    }

    Persona* buscarPersona(const std::string& codigo) const
    {
        for (const auto& p : personas)
            if (p->getCodigo() == codigo)
                return p.get();
        return nullptr;
    }

    Curso* buscarCurso(const std::string& codigo) const
    {
        for (const auto& c : cursos)
            if (c->getCodigo() == codigo)
                return c.get();
        return nullptr;
    }

    bool estaMatriculado(const Estudiante* estudiante,
                         const Curso* curso) const
    {
        for (const auto& m : matriculas)
            if (m.estudiante == estudiante && m.curso == curso)
                return true;
        return false;
    }

    // La matricula repetida se revisa antes del cupo para no ocupar un lugar
    // que no se va a usar.
    bool matricular(const Estudiante* estudiante, Curso* curso,
                    const std::string& fecha)
    {
        if (estaMatriculado(estudiante, curso) || !curso->ocuparCupo())
            return false;
        matriculas.push_back({ estudiante, curso, fecha });
        for (auto& observador : observadoresMatricula)
            observador(matriculas.back());
        return true;
    }

    size_t cantidadPersonas() const { return personas.size(); }
    size_t cantidadMatriculas() const { return matriculas.size(); }
};
