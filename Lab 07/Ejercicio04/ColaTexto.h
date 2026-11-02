#pragma once
#include <string>
#include "Cola.h"

// Especializacion para cadenas de C: guarda una copia del texto y no solo su direccion,
// asi el contenido de la cola no depende de que el arreglo original siga sin cambios.
template <>
class Cola<const char *> {
private:
    Cola<std::string> textos;

public:
    bool estaVacia() const { return textos.estaVacia(); }
    int tamanio() const { return textos.tamanio(); }

    void encolar(const char *texto) { textos.encolar(std::string(texto)); }

    std::string desencolar() { return textos.desencolar(); }

    const std::string &frente() const { return textos.frente(); }
};
