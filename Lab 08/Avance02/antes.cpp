#include "estudiante.h"
#include "docente.h"
#include <vector>

// Version sin patron: cada parte del sistema que necesita una Persona
// decide por su cuenta que subclase construir con new.

std::vector<Persona*> cargarDatosIniciales()
{
    std::vector<Persona*> personas;
    personas.push_back(new Docente("Roxana Limache", "D-0456", "Ing. de Sistemas"));
    personas.push_back(new Estudiante("Ana Torres", "20261234", "Ing. de Sistemas"));
    return personas;
}

// Recibe lo que el usuario eligio en el formulario de registro.
Persona* registrarDesdeFormulario(const std::string& tipo, const std::string& nombre,
                                  const std::string& codigo, const std::string& extra)
{
    if (tipo == "Estudiante")
        return new Estudiante(nombre, codigo, extra);
    if (tipo == "Docente")
        return new Docente(nombre, codigo, extra);
    return nullptr;
}

// Importacion de una lista de ingresantes: otro punto con new Estudiante.
void importarIngresantes(std::vector<Persona*>& personas)
{
    personas.push_back(new Estudiante("Luis Quispe", "20262001", "Ing. de Sistemas"));
    personas.push_back(new Estudiante("Maria Huaman", "20262002", "Ing. Industrial"));
}

int main()
{
    std::vector<Persona*> personas = cargarDatosIniciales();
    personas.push_back(registrarDesdeFormulario("Estudiante", "Pedro Flores", "20261500", "Ing. Civil"));
    importarIngresantes(personas);

    std::cout << "Personas registradas en el sistema de matricula:\n";
    for (Persona* p : personas)
        p->presentarse();

    for (Persona* p : personas)
        delete p;
    return 0;
}
