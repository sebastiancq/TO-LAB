#include "estudiante.h"
#include "docente.h"
#include <algorithm>
#include <stdexcept>
#include <vector>

void verificar(bool condicion, const char* mensaje)
{
    if (!condicion)
        throw std::runtime_error(mensaje);
}

int contarEstudiantes(const std::vector<Persona*>& personas)
{
    int contador = 0;
    std::for_each(personas.begin(), personas.end(), [&](const auto& persona) {
        if (dynamic_cast<const Estudiante*>(persona) != nullptr)
            ++contador;
    });
    return contador;
}

int main()
{
    std::vector<Persona*> personas;
    personas.push_back(new Estudiante("Carlos Vega", "20261111", "Sistemas"));
    personas.push_back(new Docente("Roxana Limache", "D-0456", "Sistemas"));
    personas.push_back(new Estudiante("Ana Torres", "20261234", "Sistemas"));

    for (const auto& persona : personas)
        persona->presentarse();
    const int cantidad = contarEstudiantes(personas);
    std::cout << "Total de personas: " << personas.size() << '\n';
    std::cout << "Cantidad de estudiantes: " << cantidad << '\n';
    verificar(cantidad == 2, "El vector mixto debe contener dos estudiantes");

    const std::vector<Persona*> vacio;
    verificar(contarEstudiantes(vacio) == 0, "El vector vacio debe producir cero");
    std::vector<Persona*> soloDocentes;
    soloDocentes.push_back(new Docente("Luis Perez", "D-0100", "Matematica"));
    verificar(contarEstudiantes(soloDocentes) == 0, "Un docente no debe contarse como estudiante");
    std::cout << "Estudiantes en vector vacio: " << contarEstudiantes(vacio) << '\n';
    std::cout << "Estudiantes en vector con solo docentes: " << contarEstudiantes(soloDocentes) << '\n';

    for (Persona* persona : personas)
        delete persona;
    for (Persona* docente : soloDocentes)
        delete docente;
}
