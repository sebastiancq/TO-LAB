# Laboratorio 05

## Requisitos

- Windows con MSYS2 UCRT64
- GCC (C++17)
- CMake 3.16 o superior
- Ninja
- Qt6 Widgets

## Instalación

Desde la terminal MSYS2 UCRT64:

```sh
pacman -Syu
```

```sh
pacman -S --needed \
    mingw-w64-ucrt-x86_64-gcc \
    mingw-w64-ucrt-x86_64-cmake \
    mingw-w64-ucrt-x86_64-ninja \
    mingw-w64-ucrt-x86_64-qt6-base
```

## Compilación

Desde la raíz de `Lab 05`:

**Configuración inicial**

```sh
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
```

**Compilar todos los ejercicios**

```sh
cmake --build build --parallel
```

**Compilar un ejercicio específico**

```sh
cmake --build build --target Ejercicio01 --parallel
```

Destinos disponibles: `Ejercicio01`, `Ejercicio02`, `Ejercicio03` y `Ejercicio04`.

## Ejecución

Los ejecutables se generan en `build/bin/`.

```sh
./build/bin/Ejercicio01.exe
./build/bin/Ejercicio02.exe
./build/bin/Ejercicio03.exe
./build/bin/Ejercicio04.exe
```

## Organización

```text
Lab 05/
├── CMakeLists.txt
├── Ejercicio01/
├── Ejercicio02/
├── Ejercicio03/
├── Ejercicio04/
└── README.md
```

Cada directorio contiene los archivos fuente y su respectivo `CMakeLists.txt`. Los ejercicios 03 y 04 incorporan la clase `DialogoDetalle`.


## Referencias

- [MSYS2](https://www.msys2.org/)
- [CMake](https://cmake.org/cmake/help/latest/)
- [Qt6 Widgets](https://doc.qt.io/qt-6/qtwidgets-index.html)