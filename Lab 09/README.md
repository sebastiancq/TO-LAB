# Laboratorio 09

## Compilación

Desde la carpeta `Lab 09`:

```sh
g++ Avance05/pruebas_modelo.cpp -o Avance05/pruebas_modelo
cd Avance03/Antes
qmake antes.pro
make
cd ../Despues
qmake despues.pro
make
```

En Windows con MinGW se usa `mingw32-make` en lugar de `make`.

## Ejecución

Desde la carpeta `Lab 09`:

```sh
./Avance03/Antes/antes
./Avance03/Despues/despues
./Avance05/pruebas_modelo
```
