#include <iostream>
#include <string>

using namespace std;

class Docente
{
private:
  string nombre;

public:
  explicit Docente(string nombre) : nombre(nombre) {}
  string getNombre() const { return nombre; }

  void presentarse() const
  {
    cout << "Docente: " << nombre << endl;
  }
};

class Aula
{
private:
  string codigo;
  int capacidad;

public:
  Aula(string codigo, int capacidad) : codigo(codigo), capacidad(capacidad)
  {
    cout << "Aula " << codigo << " creada, capacidad: " << capacidad
         << endl;
  }

  ~Aula()
  {
    cout << "Aula " << codigo << " liberada." << endl;
  }

  string getCodigo() const { return codigo; }
};

class Curso
{
private:
  string nombre;
  Aula aula;
  Docente *docenteAsignado;

public:
  Curso(string nombre, string codigoAula, int capacidad)
      : nombre(nombre), aula(codigoAula, capacidad), docenteAsignado(nullptr)
  {
    cout << "Curso \"" << nombre << "\" creado." << endl;
  }

  ~Curso()
  {
    cout << "Curso \"" << nombre << "\" eliminado." << endl;
  }

  void asignarDocente(Docente *docente) { docenteAsignado = docente; }

  void mostrarInfo() const
  {
    cout << "Curso: " << nombre << " << Aula: " << aula.getCodigo()
         << " << Docente: "
         << (docenteAsignado ? docenteAsignado->getNombre() : "sin asignar")
         << endl;
  }
};

int main()
{
  Docente docente("Mg. Roxana Limache");
  {
    Curso curso("Programacion Web", "B-101", 25);
    curso.asignarDocente(&docente);
    curso.mostrarInfo();
    cout << "fin del bloque: el Curso se destruye" << endl;
  }

  cout << "El docente sigue existiendo (agregacion): ";
  docente.presentarse();
  return 0;
}