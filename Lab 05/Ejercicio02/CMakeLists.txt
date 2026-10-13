
add_executable(Ejercicio02
    main.cpp
    VentanaRegistro.h
    VentanaRegistro.cpp
    Estudiante.h
    Estudiante.cpp
)

target_link_libraries(Ejercicio02
    PRIVATE Qt6::Widgets
)
