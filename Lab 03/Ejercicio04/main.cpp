#include <iostream>
#include <memory>
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
};

class Estudiante : public Persona
{
public:
  Estudiante(string nombre, string codigo)
      : Persona(nombre, codigo) {}

  void presentarse() const override
  {
    cout << "Soy el estudiante " << nombre << " (" << codigo << ")"
         << endl;
  }
};

class Docente : public Persona
{
public:
  Docente(string nombre, string codigo)
      : Persona(nombre, codigo) {}

  void presentarse() const override
  {
    cout << "Soy el docente " << nombre << " (" << codigo << ")"
         << endl;
  }
};

class Administrativo : public Persona
{
public:
  Administrativo(string nombre, string codigo)
      : Persona(nombre, codigo) {}

  void presentarse() const override
  {
    cout << "Soy el administrativo " << nombre << " (" << codigo << ")"
         << endl;
  }
};

int main()
{
  vector<unique_ptr<Persona>> personas;
  personas.push_back(make_unique<Estudiante>("Ana Torres", "20261234"));
  personas.push_back(make_unique<Docente>("Mg. Roxana Limache", "D-0456"));
  personas.push_back(make_unique<Administrativo>("Carlos Meza", "A-0789"));

  for (const auto &persona : personas)
    persona->presentarse();

  return 0;
}
