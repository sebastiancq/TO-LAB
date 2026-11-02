#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T> *siguiente;

    Nodo(T dato) : dato(dato), siguiente(nullptr) {}
};

template <typename T>
class Cola {
private:
    Nodo<T> *frenteNodo;
    Nodo<T> *finNodo;
    int tamano;

public:
    Cola() : frenteNodo(nullptr), finNodo(nullptr), tamano(0) {}

    ~Cola() {
        while (!estaVacia()) desencolar();
    }

    bool estaVacia() const { return frenteNodo == nullptr; }
    int tamanio() const { return tamano; }

    void encolar(T dato) {
        Nodo<T> *nuevo = new Nodo<T>(dato);
        if (estaVacia()) {
            frenteNodo = nuevo;
        } else {
            finNodo->siguiente = nuevo;
        }
        finNodo = nuevo;
        tamano++;
    }

    T desencolar() {
        if (estaVacia()) throw std::runtime_error("La cola esta vacia");
        Nodo<T> *viejo = frenteNodo;
        T dato = viejo->dato;
        frenteNodo = frenteNodo->siguiente;
        if (frenteNodo == nullptr) finNodo = nullptr;
        delete viejo;
        tamano--;
        return dato;
    }

    // Consulta el primer elemento sin quitarlo de la cola.
    const T &frente() const {
        if (estaVacia()) throw std::runtime_error("La cola esta vacia");
        return frenteNodo->dato;
    }
};
