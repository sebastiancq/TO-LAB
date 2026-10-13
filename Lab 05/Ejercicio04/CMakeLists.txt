
add_executable(Ejercicio04
    main.cpp
    VentanaRegistro.h
    VentanaRegistro.cpp
    Estudiante.h
    Estudiante.cpp
    DialogoDetalle.h
    DialogoDetalle.cpp
)

target_link_libraries(Ejercicio04
    PRIVATE Qt6::Widgets
)
