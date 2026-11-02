#pragma once
#include <stdexcept>

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T> *siguiente;

    Nodo(T dato) : dato(dato), siguiente(nullptr) {}
};

template <typename T>
class Pila {
private:
    Nodo<T> *topeNodo;
    int tamano;

public:
    Pila() : topeNodo(nullptr), tamano(0) {}

    ~Pila() {
        while (!estaVacia()) pop();
    }

    bool estaVacia() const { return topeNodo == nullptr; }
    int tamanio() const { return tamano; }

    // El nuevo nodo queda encima y apunta al que era el tope.
    void push(T dato) {
        Nodo<T> *nuevo = new Nodo<T>(dato);
        nuevo->siguiente = topeNodo;
        topeNodo = nuevo;
        tamano++;
    }

    T pop() {
        if (estaVacia()) throw std::runtime_error("La pila esta vacia");
        Nodo<T> *viejo = topeNodo;
        T dato = viejo->dato;
        topeNodo = topeNodo->siguiente;
        delete viejo;
        tamano--;
        return dato;
    }

    const T &tope() const {
        if (estaVacia()) throw std::runtime_error("La pila esta vacia");
        return topeNodo->dato;
    }
};
