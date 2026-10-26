#include "estudiante.h"
#include "docente.h"
#include "administrativo.h"
#include <stdexcept>
#include <typeinfo>
#include <vector>

void verificar(bool condicion, const char* mensaje)
{
    if (!condicion)
        throw std::runtime_error(mensaje);
}

int main()
{
    std::vector<Persona*> personas;
    personas.push_back(new Estudiante("Ana Torres", "20261234", "Sistemas"));
    personas.push_back(new Docente("Roxana Limache", "D-0456", "Sistemas"));
    personas.push_back(new Administrativo("Carlos Meza", "A-0789", "Recursos Humanos"));

    for (const auto& persona : personas)
    {
        Persona* copia = persona->clonar();
        std::cout << "Original: ";
        persona->presentarse();
        std::cout << "Clon: ";
        copia->presentarse();
        verificar(copia != persona && *copia == *persona, "Clon incorrecto");
        verificar(typeid(*copia) == typeid(*persona), "El clon debe conservar el tipo dinamico");
        delete copia;
    }

    const Administrativo original("Maria Lopez", "A-0100", "Biblioteca");
    Administrativo* copia = original.clonar();
    verificar(copia->getArea() == original.getArea(), "El clon debe conservar su area");
    std::cout << "Area: " << copia->getArea() << '\n';

    delete copia;
    for (Persona* persona : personas)
        delete persona;
}
