// Comprueba las reglas de SistemaMatricula llamando directamente a sus
// metodos y contando los avisos que reciben sus observadores.
#include "../Avance03/Despues/SistemaMatricula.h"
#include "../Avance03/Despues/tiposPersona.h"
#include <iostream>
#include <string>

int superadas = 0;
int total = 0;

void verificar(bool condicion, const std::string& descripcion)
{
    total++;
    if (condicion)
        superadas++;
    std::cout << (condicion ? "Superada  " : "FALLIDA   ") << descripcion
              << '\n';
}

int main()
{
    registrarTiposDePersona();
    SistemaMatricula modelo;

    int avisosRegistro = 0;
    int avisosMatricula = 0;
    modelo.agregarObservadorRegistro([&avisosRegistro](const Persona&)
                                     { avisosRegistro++; });
    modelo.agregarObservador([&avisosMatricula](const Matricula&)
                             { avisosMatricula++; });

    Curso& to = modelo.registrarCurso(
        std::make_unique<Curso>("TO-401", "Tecnologia de Objetos", "301", 2));

    verificar(modelo.registrarPersona(PersonaFactory::crearPersona(
                  "Estudiante", "Ana Torres", "20261234", "Sistemas")),
              "Registra a Ana Torres");
    verificar(!modelo.registrarPersona(PersonaFactory::crearPersona(
                  "Docente", "Otro", "20261234", "Sistemas")),
              "Rechaza un codigo repetido");
    verificar(modelo.cantidadPersonas() == 1 && avisosRegistro == 1,
              "El registro rechazado no se guarda ni se notifica");

    modelo.registrarPersona(PersonaFactory::crearPersona(
        "Estudiante", "Luis Quispe", "20262001", "Sistemas"));
    modelo.registrarPersona(PersonaFactory::crearPersona(
        "Estudiante", "Maria Huaman", "20262002", "Industrial"));
    auto* ana = dynamic_cast<Estudiante*>(modelo.buscarPersona("20261234"));
    auto* luis = dynamic_cast<Estudiante*>(modelo.buscarPersona("20262001"));
    auto* maria = dynamic_cast<Estudiante*>(modelo.buscarPersona("20262002"));

    verificar(modelo.matricular(ana, &to, "13/11/2026") &&
                  modelo.matricular(luis, &to, "13/11/2026"),
              "Matricula a dos estudiantes en un aula de capacidad 2");
    verificar(!modelo.matricular(maria, &to, "14/11/2026"),
              "Rechaza la tercera matricula por falta de cupo");
    verificar(avisosMatricula == 2 && modelo.cantidadMatriculas() == 2,
              "Solo las matriculas confirmadas llegan a los observadores");

    Curso& ada = modelo.registrarCurso(std::make_unique<Curso>(
        "ADA-402", "Analisis y Diseno de Algoritmos", "205", 30));
    modelo.matricular(maria, &ada, "14/11/2026");
    verificar(!modelo.matricular(maria, &ada, "14/11/2026") &&
                  ada.getInscritos() == 1,
              "Rechaza una matricula repetida sin ocupar otro cupo");

    std::cout << '\n' << superadas << " de " << total << " pruebas superadas\n";
    return superadas == total ? 0 : 1;
}
