#include <iostream>
#include "Curso.h"
using namespace std;
int main() {
    
    Curso miCurso("Tecnologia de Objetos", 30);
    
    cout << "\nMATRICULANDO ESTUDIANTES" << endl;

    miCurso.matricularEstudiante(new Estudiante("Juan Perez", "20260001"));
    miCurso.matricularEstudiante(new Estudiante("Maria Lopez", "20260002"));
    miCurso.matricularEstudiante(new Estudiante("Carlos Ruiz", "20260003"));
    miCurso.matricularEstudiante(new Estudiante("Ana Torres", "20260004"));
    miCurso.matricularEstudiante(new Estudiante("Luis Fernandez", "20260005"));
    miCurso.matricularEstudiante(new Estudiante("Sofia Martinez", "20260006"));
    miCurso.matricularEstudiante(new Estudiante("Diego Ramirez", "20260007"));
    
    miCurso.mostrarMatriculados();
    
    cout << "\nFIN DEL PROGRAMA" << endl;
    
    // Su destructor ~Curso() se llama automáticamente y ejecuta todos los 'delete'.
    return 0;
}