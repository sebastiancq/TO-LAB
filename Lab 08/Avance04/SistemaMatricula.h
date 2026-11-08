#pragma once

#include "estudiante.h"
#include "curso.h"
#include <functional>
#include <vector>

struct Matricula
{
    const Estudiante* estudiante;
    const Curso* curso;
    std::string fecha;
};

// Sujeto del patron Observer: avisa a cada observador registrado cuando
// se confirma una matricula, sin conocer que hace cada uno con el aviso.
class SistemaMatricula
{
private:
    std::vector<Persona*> personas;
    std::vector<Curso*> cursos;
    std::vector<Matricula> matriculas;
    std::vector<std::function<void(const Matricula&)>> observadores;

public:
    SistemaMatricula() = default;
    SistemaMatricula(const SistemaMatricula&) = delete;
    SistemaMatricula& operator=(const SistemaMatricula&) = delete;

    ~SistemaMatricula()
    {
        for (Persona* p : personas)
            delete p;
        for (Curso* c : cursos)
            delete c;
    }

    void agregarObservador(std::function<void(const Matricula&)> observador)
    {
        observadores.push_back(observador);
    }

    // El sistema toma posesion de lo que se registra y lo libera al final.
    void registrarPersona(Persona* persona) { personas.push_back(persona); }
    void registrarCurso(Curso* curso) { cursos.push_back(curso); }

    bool matricular(const Estudiante* estudiante, Curso* curso, const std::string& fecha)
    {
        if (!curso->ocuparCupo())
            return false;
        matriculas.push_back({ estudiante, curso, fecha });
        for (auto& observador : observadores)
            observador(matriculas.back());
        return true;
    }

    size_t cantidadMatriculas() const { return matriculas.size(); }
};
