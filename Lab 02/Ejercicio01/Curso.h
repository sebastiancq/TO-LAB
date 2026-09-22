#include <iostream>
#include <string>

class Curso {
private:
    std::string nombre;
    int capacidad;

public:
    Curso(std::string nombre, int capacidad) : nombre(nombre), capacidad(capacidad) {
        std::cout << "[Traza] Curso creado: " << nombre 
                  << " | Capacidad: " << capacidad << " estudiantes." << std::endl;
    }

    ~Curso() {
        std::cout << "[Traza] Curso destruido: " << nombre << std::endl;
    }

    std::string getNombre() const { 
        return nombre; 
    }
    
    int getCapacidad() const { 
        return capacidad; 
    }

    void setNombre(std::string n) { 
        nombre = n; 
    }
    
    void setCapacidad(int c) { 
        capacidad = c; 
    }
};
