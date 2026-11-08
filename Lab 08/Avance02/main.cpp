#include "PersonaFactory.h"
#include <vector>

// Los mismos tres puntos de creacion de antes.cpp, ahora delegados a PersonaFactory.

std::vector<Persona*> cargarDatosIniciales()
{
    std::vector<Persona*> personas;
    personas.push_back(PersonaFactory::crearPersona(
        TipoPersona::DOCENTE, "Roxana Limache", "D-0456", "Ing. de Sistemas"));
    personas.push_back(PersonaFactory::crearPersona(
        TipoPersona::ESTUDIANTE, "Ana Torres", "20261234", "Ing. de Sistemas"));
    return personas;
}

Persona* registrarDesdeFormulario(const std::string& tipo, const std::string& nombre,
                                  const std::string& codigo, const std::string& extra)
{
    return PersonaFactory::crearPersona(PersonaFactory::tipoDesdeTexto(tipo), nombre, codigo, extra);
}

void importarIngresantes(std::vector<Persona*>& personas)
{
    personas.push_back(PersonaFactory::crearPersona(
        TipoPersona::ESTUDIANTE, "Luis Quispe", "20262001", "Ing. de Sistemas"));
    personas.push_back(PersonaFactory::crearPersona(
        TipoPersona::ESTUDIANTE, "Maria Huaman", "20262002", "Ing. Industrial"));
}

int main()
{
    std::vector<Persona*> personas = cargarDatosIniciales();
    personas.push_back(registrarDesdeFormulario("Estudiante", "Pedro Flores", "20261500", "Ing. Civil"));
    importarIngresantes(personas);

    std::cout << "Personas registradas en el sistema de matricula:\n";
    for (Persona* p : personas)
        p->presentarse();

    // Un tipo que el formulario no ofrece se rechaza en un solo lugar.
    try
    {
        Persona* p = registrarDesdeFormulario("Visitante", "Jose Ramos", "V-0001", "");
        delete p;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Registro rechazado: " << e.what() << '\n';
    }

    for (Persona* p : personas)
        delete p;
    return 0;
}
