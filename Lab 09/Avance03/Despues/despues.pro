QT += widgets
CONFIG += c++17
CONFIG -= debug_and_release
TARGET = despues
TEMPLATE = app
SOURCES += main.cpp VistaRegistro.cpp ControladorRegistro.cpp
HEADERS += persona.h estudiante.h docente.h PersonaFactory.h tiposPersona.h curso.h \
           SistemaMatricula.h VistaRegistro.h ControladorRegistro.h
