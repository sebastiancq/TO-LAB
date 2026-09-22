#include <iostream>
#include <string>
#include <vector>
#include "Estudiante.h"
using namespace std;
class Curso
{
private:
  string nombre;
  size_t capacidad;
  vector<Estudiante *> matriculados;

public:
  Curso(string nombre, size_t capacidad) : nombre(nombre), capacidad(capacidad)
  {
    cout << "Traza: Curso creado -> " << nombre << " (Capacidad: " << capacidad << ")" << endl;
  }

  ~Curso()
  {
    cout << "Traza: Destruyendo curso y liberando memoria de los estudiantes" << endl;
    for (size_t i = 0; i < matriculados.size(); i++)
    {
      delete matriculados[i]; // Previene la fuga de memoria (memory leak)
    }
    matriculados.clear();
    cout << "Traza: Curso destruido " << nombre << endl;
  }

  void matricularEstudiante(Estudiante *estudiante)
  {
    if (matriculados.size() < capacidad)
    {
      matriculados.push_back(estudiante);
    }
    else
    {
      cout << "Error: Capacidad maxima del curso alcanzada." << endl;
      delete estudiante;
    }
  }

  void mostrarMatriculados() const
  {
    cout << "\nLISTA DE MATRICULADOS EN: " << nombre << endl;
    for (size_t i = 0; i < matriculados.size(); i++)
    {
      matriculados[i]->mostrarDatos();
    }
  }

  string getNombre() const { return nombre; }
  int getCapacidad() const { return capacidad; }
  void setNombre(string n) { nombre = n; }
  void setCapacidad(int c) { capacidad = c; }
};