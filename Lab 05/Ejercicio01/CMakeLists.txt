add_executable(Ejercicio01
    main.cpp
    VentanaRegistro.h
    VentanaRegistro.cpp
    Estudiante.h
    Estudiante.cpp
)

target_link_libraries(Ejercicio01
    PRIVATE Qt6::Widgets
)
