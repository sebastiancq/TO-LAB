# Laboratorio 06: Tecnología de Objetos

Se trabaja con la clase abstracta `Persona` y sus clases derivadas para practicar sobrecarga de operadores, métodos constantes, expresiones lambda, polimorfismo y covarianza. Cada ejercicio tiene su propio programa y las cabeceras que utiliza.

## Ejercicios

- **01. Comparación de objetos.** Sobrecarga `==`, `!=` y `<` para comparar personas mediante su código. El operador `<<` permite mostrar nombre y código en consola; las consultas constantes permiten trabajar con objetos `const`.
- **02. Datos específicos y clonación.** `Estudiante` incorpora una carrera y `Docente` un departamento. Sus métodos `clonar()` devuelven `Estudiante*` y `Docente*`, respectivamente, aunque la clase base declara `Persona*`. Las copias conservan sus datos y se liberan con `delete`.
- **03. Conteo con lambda.** Recorre un vector mixto de `Persona*` mediante `for_each`. Una lambda captura el contador por referencia y utiliza `dynamic_cast` para contar únicamente estudiantes. También contempla un vector vacío y otro formado solo por docentes.
- **04. Ampliación de la jerarquía.** Añade `Administrativo`, con el atributo `area`. Se presentan y clonan los objetos mediante punteros a `Persona`, comprobando que cada copia conserva sus datos y su tipo dinámico. Los objetos creados con `new` se liberan al terminar.

## Ejercicio 05: Covarianza y contravarianza

Es explicativo y no tiene ejecutable. C++ permite que un método virtual sobrescrito devuelva un puntero o referencia a una clase derivada: por ejemplo, `Administrativo*` en lugar de `Persona*`. Esto es covarianza del retorno.

Los tipos de los parámetros deben coincidir al sobrescribir el método; recibir un tipo más general no constituye una sobrescritura. Un manejador que acepta `const Persona&` puede recibir un estudiante mediante la conversión de derivada a base, pero eso no cambia esta regla de los métodos virtuales.

## Compilación y ejecución

Desde la carpeta `Lab 06`:

```sh
g++ Ejercicio01/main.cpp -o Ejercicio01/main.exe
g++ Ejercicio02/main.cpp -o Ejercicio02/main.exe
g++ Ejercicio03/main.cpp -o Ejercicio03/main.exe
g++ Ejercicio04/main.cpp -o Ejercicio04/main.exe

./Ejercicio01/main.exe
./Ejercicio02/main.exe
./Ejercicio03/main.exe
./Ejercicio04/main.exe
```
