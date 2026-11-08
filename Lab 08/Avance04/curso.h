#pragma once

#include <string>
#include <utility>

// El aula forma parte del curso por composicion: se crea y se destruye con el.
class Aula
{
private:
    std::string codigo;
    int capacidad;

public:
    Aula(std::string codigo, int capacidad) : codigo(std::move(codigo)), capacidad(capacidad) {}

    const std::string& getCodigo() const { return codigo; }
    int getCapacidad() const { return capacidad; }
};

class Curso
{
private:
    std::string codigo;
    std::string nombre;
    Aula aula;
    int inscritos = 0;

public:
    Curso(std::string codigo, std::string nombre, std::string codigoAula, int capacidad)
        : codigo(std::move(codigo)), nombre(std::move(nombre)), aula(std::move(codigoAula), capacidad) {}

    const std::string& getCodigo() const { return codigo; }
    const std::string& getNombre() const { return nombre; }
    const Aula& getAula() const { return aula; }
    int getInscritos() const { return inscritos; }
    int cuposLibres() const { return aula.getCapacidad() - inscritos; }

    bool ocuparCupo()
    {
        if (cuposLibres() == 0)
            return false;
        inscritos++;
        return true;
    }
};
