QT += widgets
CONFIG += c++17
CONFIG -= debug_and_release
TARGET = antes
TEMPLATE = app
SOURCES += main.cpp VentanaRegistro.cpp
HEADERS += persona.h estudiante.h docente.h PersonaFactory.h tiposPersona.h curso.h VentanaRegistro.h
