#include "FuncionesGenericas.h"
#include "Estudiante.h"
#include "Cola.h"

int main() {
    Cola<Estudiante> turnosAtencion;
    turnosAtencion.encolar(Estudiante("Ana Torres", "20261234"));
    turnosAtencion.encolar(Estudiante("Carlos Vega", "20261111"));
    turnosAtencion.encolar(Estudiante("Luis Perez", "20265678"));

    std::cout << "Orden de atencion (FIFO)" << std::endl;
    while (!turnosAtencion.estaVacia()) {
        std::cout << "Siguiente en ser atendido: ";
        turnosAtencion.frente().mostrarDatos(); // consulta sin desencolar
        std::cout << "En espera: " << turnosAtencion.tamanio() << std::endl;

        Estudiante siguiente = turnosAtencion.desencolar();
        std::cout << "Atendido: ";
        siguiente.mostrarDatos(); // el primero en llegar es el primero en ser atendido
        std::cout << std::endl;
    }

    try {
        turnosAtencion.frente();
    } catch (const std::runtime_error &error) {
        std::cout << "Consulta con la cola vacia: " << error.what() << std::endl;
    }

    std::cout << std::endl;

    Cola<std::string> historialMensajes;
    historialMensajes.encolar("Turno 1: Ana Torres registrada");
    historialMensajes.encolar("Turno 2: Carlos Vega registrado");
    historialMensajes.encolar("Turno 3: Luis Perez registrado");

    std::cout << "Historial de mensajes" << std::endl;
    while (!historialMensajes.estaVacia()) {
        mostrarElemento(historialMensajes.desencolar());
    }

    return 0;
}
