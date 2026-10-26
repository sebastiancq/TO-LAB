#include "estudiante.h"
#include "docente.h"
#include <stdexcept>

void verificar(bool condicion, const char* mensaje)
{
    if (!condicion)
        throw std::runtime_error(mensaje);
}

int main()
{
    const Estudiante ana("Ana Torres", "20261234", "Ingenieria de Sistemas");
    const Estudiante copia("Ana Torres", "20261234", "Ingenieria de Sistemas");
    const Docente docente("Roxana Limache", "D-0456", "Sistemas");

    std::cout << std::boolalpha;
    std::cout << "Ana: " << ana << '\n';
    std::cout << "Copia: " << copia << '\n';
    std::cout << "Docente: " << docente << '\n';
    std::cout << "Ana == copia: " << (ana == copia) << '\n';
    std::cout << "Ana != copia: " << (ana != copia) << '\n';
    std::cout << "Ana != docente: " << (ana != docente) << '\n';
    std::cout << "Codigo de Ana < codigo del docente: " << (ana < docente) << '\n';
    std::cout << "Codigo del docente < codigo de Ana: " << (docente < ana) << '\n';

    verificar(ana == copia && !(ana != copia), "Fallo al comparar codigos iguales");
    verificar(ana != docente, "Fallo al comparar codigos distintos");
    verificar(ana < docente && !(docente < ana) && !(ana < copia), "Fallo de orden por codigo");
}
