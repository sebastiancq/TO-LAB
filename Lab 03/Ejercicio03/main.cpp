#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Curso
{
private:
  string nombre;
  string codigo;

public:
  Curso(const string &nombre, const string &codigo)
      : nombre(nombre), codigo(codigo)
  {
    cout << "Curso creado: " << nombre << '\n';
  }

  ~Curso()
  {
    cout << "Curso destruido: " << nombre << '\n';
  }

  const string &getNombre() const
  {
    return nombre;
  }

  const string &getCodigo() const
  {
    return codigo;
  }

  void mostrarInformacion() const
  {
    cout << codigo << " - " << nombre << '\n';
  }
};

class Persona
{
protected:
  string nombre;
  string codigo;

public:
  Persona(const string &nombre, const string &codigo)
      : nombre(nombre), codigo(codigo) {}

  virtual ~Persona() = default;

  virtual void presentarse() const = 0;
};

class Estudiante : public Persona
{
private:
  string carrera;

  // Asociación: Estudiante no es propietario de los cursos.
  vector<Curso*> cursosMatriculados;

public:
  Estudiante(const string &nombre,
             const string &codigo,
             const string &carrera)
      : Persona(nombre, codigo), carrera(carrera)
  {
    cout << "Estudiante creado: " << nombre << '\n';
  }

  ~Estudiante() override
  {
    cout << "Estudiante destruido: " << nombre << '\n';
  }

  void presentarse() const override
  {
    cout << "Soy el estudiante " << nombre
         << " (" << codigo << "), carrera: "
         << carrera << '\n';
  }

  void matricular(Curso *curso)
  {
    if (curso == nullptr)
    {
      cout << "No se puede matricular en un curso nulo.\n";
      return;
    }

    cursosMatriculados.push_back(curso);

    cout << nombre << " fue matriculado en "
         << curso->getNombre() << ".\n";
  }

  void mostrarCursos() const
  {
    cout << "\nCursos matriculados de " << nombre << ":\n";

    if (cursosMatriculados.empty())
    {
      cout << "No tiene cursos matriculados.\n";
      return;
    }

    for (const Curso *curso : cursosMatriculados)
    {
      if (curso != nullptr)
      {
        cout << curso->getCodigo()
             << ": " << curso->getNombre() << '\n';
      }
    }
  }
};

int main()
{
  // Los cursos existen independientemente del estudiante.
  Curso curso1("Tecnologia de Objetos", "TO-301");
  Curso curso2("Base de Datos", "BD-302");

  cout << "\nCreacion y matricula del estudiante\n";

  {
    Estudiante estudiante(
        "Ana Torres",
        "20261234",
        "Ingenieria de Sistemas");

    estudiante.presentarse();
    estudiante.matricular(&curso1);
    estudiante.matricular(&curso2);

    estudiante.mostrarCursos();

    cout << "\nFin del bloque del estudiante.\n";
  }
  // El estudiante ya fue destruido, pero los cursos siguen existiendo.
  cout << "\nLos cursos siguen existiendo\n";
  curso1.mostrarInformacion();
  curso2.mostrarInformacion();

  Estudiante estudiante(
      "Luis Perez",
      "20265678",
      "Ingenieria de Sistemas");

  estudiante.presentarse();
  estudiante.mostrarCursos();

  return 0;
}