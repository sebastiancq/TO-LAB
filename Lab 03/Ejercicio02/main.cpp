#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Persona
{
protected:
  string nombre;
  string codigo;

public:
  Persona(string nombre, string codigo)
      : nombre(nombre), codigo(codigo) {}
  virtual ~Persona() {}
  virtual void presentarse() const = 0;
  string getNombre() const { return nombre; }
};

class Evaluable
{
public:
  virtual ~Evaluable() {}
  virtual double calcularNota() const = 0;
};

class Estudiante : public Persona, public Evaluable
{
private:
  string carrera;
  vector<double> notas;

public:
  Estudiante(string nombre, string codigo, string carrera)
      : Persona(nombre, codigo), carrera(carrera) {}

  void presentarse() const override
  {
    cout << "Soy el estudiante " << nombre << " (" << codigo
         << "), carrera: " << carrera << endl;
  }

  void agregarNota(double nota) { notas.push_back(nota); }

  double calcularNota() const override
  {
    if (notas.empty())
      return 0.0;

    double suma = 0.0;
    for (double nota : notas)
      suma += nota;
    return suma / notas.size();
  }
};

int main()
{
  Estudiante estudiante("Ana Torres", "20261234", "Ingenieria de Sistemas");
  estudiante.agregarNota(15.0);
  estudiante.agregarNota(20.0);
  estudiante.agregarNota(12.0);

  double promedio = estudiante.calcularNota();
  cout << "Promedio de " << estudiante.getNombre() << ": " << promedio << endl;

  return 0;
}
