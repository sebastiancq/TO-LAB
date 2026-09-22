#include <iostream>
#include <string>
using namespace std;
class Estudiante
{
private:
  std::string nombre;
  std::string codigo;

public:
  Estudiante(std::string nombre, std::string codigo)
      : nombre(nombre), codigo(codigo)
  {
    std::cout << "Estudiante creado: " << nombre << std::endl;
  }
  ~Estudiante()
  {
    std::cout << "Estudiante destruido: " << nombre << std::endl;
  }
  std::string getNombre() const { return nombre; }
  void setNombre(std::string n) { nombre = n; }
  void mostrarDatos() const
  {
    std::cout << "Estudiante: " << nombre
              << " (" << codigo << ")" << std::endl;
  }
};