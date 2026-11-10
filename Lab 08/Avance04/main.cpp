#include "tiposPersona.h"
#include "SistemaMatricula.h"

int main()
{
    registrarTiposDePersona();
    SistemaMatricula sistema;

    // Observador 1: agrega la fila nueva a la tabla de consulta de matriculas.
    sistema.agregarObservador([](const Matricula& m) {
        std::cout << "Tabla de consulta: " << m.fecha << ", " << m.estudiante->getCodigo()
                  << ", " << m.estudiante->getNombre() << ", " << m.curso->getNombre() << '\n';
    });

    // Observador 2: controla el aforo del aula y avisa cuando ya no quedan cupos.
    sistema.agregarObservador([](const Matricula& m) {
        const Curso& c = *m.curso;
        std::cout << "Control de aforo: aula " << c.getAula().getCodigo() << " con "
                  << c.getInscritos() << " de " << c.getAula().getCapacidad() << " cupos ocupados";
        if (c.cuposLibres() == 0)
            std::cout << ", el curso ya no acepta matriculas";
        std::cout << '\n';
    });

    // Observador 3: emite la constancia que recibe el estudiante.
    sistema.agregarObservador([](const Matricula& m) {
        std::cout << "Constancia: matricula de " << m.estudiante->getNombre() << " en "
                  << m.curso->getNombre() << "\n\n";
    });

    Curso* poo = new Curso("TO-401", "Tecnologia de Objetos", "301", 2);
    Curso* ada = new Curso("ADA-402", "Analisis y Diseno de Algoritmos", "205", 30);
    sistema.registrarCurso(poo);
    sistema.registrarCurso(ada);

    // Las personas se crean con la fabrica del avance 2.
    Persona* ana = PersonaFactory::crearPersona("Estudiante", "Ana Torres", "20261234", "Ing. de Sistemas");
    Persona* luis = PersonaFactory::crearPersona("Estudiante", "Luis Quispe", "20262001", "Ing. de Sistemas");
    Persona* maria = PersonaFactory::crearPersona("Estudiante", "Maria Huaman", "20262002", "Ing. Industrial");
    sistema.registrarPersona(ana);
    sistema.registrarPersona(luis);
    sistema.registrarPersona(maria);

    // La factory devuelve Persona*; la matricula necesita saber que es un Estudiante.
    auto comoEstudiante = [](Persona* p) { return dynamic_cast<Estudiante*>(p); };

    sistema.matricular(comoEstudiante(ana), poo, "09/11/2026");
    sistema.matricular(comoEstudiante(luis), poo, "09/11/2026");
    if (!sistema.matricular(comoEstudiante(maria), poo, "10/11/2026"))
        std::cout << "Matricula rechazada: " << maria->getNombre() << " no tiene cupo en "
                  << poo->getNombre() << ", no se notifica a los observadores\n\n";
    sistema.matricular(comoEstudiante(maria), ada, "10/11/2026");

    std::cout << "Total de matriculas confirmadas: " << sistema.cantidadMatriculas() << '\n';
    return 0;
}
