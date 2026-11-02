#include <iostream>
#include <string>
#include "Pila.h"

// Una accion guarda lo necesario para revertirla: si se escribio o se borro, y que texto.
struct Accion {
    bool esEscritura;
    std::string texto;
};

class EditorTexto {
private:
    std::string contenido;
    Pila<Accion> historial;

public:
    void escribir(const std::string &texto) {
        contenido += texto;
        historial.push({true, texto});
        mostrar("Escribir \"" + texto + "\"");
    }

    void borrar(int cantidad) {
        if (cantidad > static_cast<int>(contenido.size())) cantidad = contenido.size();
        std::string borrado = contenido.substr(contenido.size() - cantidad);
        contenido.erase(contenido.size() - cantidad);
        historial.push({false, borrado});
        mostrar("Borrar \"" + borrado + "\"");
    }

    void deshacer() {
        if (historial.estaVacia()) {
            std::cout << "Deshacer: no hay acciones pendientes" << std::endl;
            return;
        }
        Accion ultima = historial.pop();
        if (ultima.esEscritura) {
            contenido.erase(contenido.size() - ultima.texto.size());
            mostrar("Deshacer escritura de \"" + ultima.texto + "\"");
        } else {
            contenido += ultima.texto;
            mostrar("Deshacer borrado de \"" + ultima.texto + "\"");
        }
    }

    void mostrar(const std::string &accion) const {
        std::cout << accion << ". Texto: \"" << contenido << "\". Historial: "
                  << historial.tamanio() << std::endl;
    }
};

int main() {
    EditorTexto editor;

    editor.escribir("Hola");
    editor.escribir(" mundo");
    editor.borrar(5);
    editor.escribir("equipo");

    std::cout << std::endl;

    editor.deshacer();
    editor.deshacer();
    editor.deshacer();
    editor.deshacer();
    editor.deshacer();

    return 0;
}
