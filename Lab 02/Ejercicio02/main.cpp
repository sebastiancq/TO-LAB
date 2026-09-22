#include <iostream>
#include <string>
#include "Curso.h"

void modificarPorValor(Curso c) {
    std::cout << "  -> [Dentro de modificarPorValor] Cambiando capacidad a 40..." << std::endl;
    c.setCapacidad(40);
}

void modificarPorReferencia(Curso &c) {
    std::cout << "  -> [Dentro de modificarPorReferencia] Cambiando capacidad a 50" << std::endl;
    c.setCapacidad(50);
}

int main() {
    std::cout << "CREACION DEL OBJETO" << std::endl;
    Curso miCurso("Tecnologia de Objetos", 30);

    //Paso por valor
    std::cout << "\nPRUEBA POR VALOR" << std::endl;
    std::cout << "Antes de la funcion: Capacidad = " << miCurso.getCapacidad() << std::endl;
    modificarPorValor(miCurso);
    std::cout << "Despues de la funcion: Capacidad = " << miCurso.getCapacidad() << std::endl;

    //Paso por referencia
    std::cout << "\nPRUEBA POR REFERENCIA" << std::endl;
    std::cout << "Antes de la funcion: Capacidad = " << miCurso.getCapacidad() << std::endl;
    modificarPorReferencia(miCurso);
    std::cout << "Despues de la funcion: Capacidad = " << miCurso.getCapacidad() << std::endl;

    std::cout << "\nFIN DEL PROGRAMA" << std::endl;
    return 0;
}