#include <cstring>
#include <iostream>
#include "Cola.h"
#include "ColaTexto.h"

int main() {
    const char *nombres[] = {"Ana Torres", "Carlos Vega", "Luis Perez"};
    char buffer[40]; // el mismo arreglo se reutiliza para leer cada nombre

    // char* usa la version generica: cada nodo guarda la direccion de buffer.
    Cola<char *> colaGenerica;
    // const char* usa la especializacion: cada nodo guarda su propia copia del texto.
    Cola<const char *> colaEspecializada;

    for (const char *nombre : nombres) {
        std::strcpy(buffer, nombre);
        colaGenerica.encolar(buffer);
        colaEspecializada.encolar(buffer);
    }

    std::cout << "Cola<char*>, version generica" << std::endl;
    while (!colaGenerica.estaVacia()) {
        std::cout << colaGenerica.desencolar() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Cola<const char*>, especializacion" << std::endl;
    std::cout << "Siguiente: " << colaEspecializada.frente() << std::endl;
    while (!colaEspecializada.estaVacia()) {
        std::cout << colaEspecializada.desencolar() << std::endl;
    }

    return 0;
}
