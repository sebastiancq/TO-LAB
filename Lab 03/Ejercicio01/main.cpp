#include <iostream>
#include <string>

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
};

class Estudiante : public Persona
{
public:
  Estudiante(string nombre, string codigo)
      : Persona(nombre, codigo) {}

  void presentarse() const override
  {
    cout << "Soy el estudiante " << nombre << " (" << codigo << ")" << endl;
  }
};

class Docente : public Persona
{
public:
  Docente(string nombre, string codigo)
      : Persona(nombre, codigo) {}

  void presentarse() const override
  {
    cout << "Soy el docente " << nombre << " (" << codigo << ")" << endl;
  }
};

class Administrativo : public Persona
{
private:
  string area;

public:
  Administrativo(string nombre, string codigo, string area)
      : Persona(nombre, codigo), area(area) {}

  void presentarse() const override
  {
    cout << "Soy el administrativo " << nombre << " (" << codigo
         << "), area: " << area << endl;
  }
};
int main()
{
  Estudiante estudiante("Ana Torres", "20261234");
  Docente docente("Mg. Roxana Limache", "D-0456");
  Administrativo administrativo("Carlos Meza", "A-0789", "Recursos Humanos");
  estudiante.presentarse();
  docente.presentarse();
  administrativo.presentarse();
  return 0;
}
