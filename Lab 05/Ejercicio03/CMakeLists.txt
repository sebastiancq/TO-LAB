
add_executable(Ejercicio03
    main.cpp
    VentanaRegistro.h
    VentanaRegistro.cpp
    Estudiante.h
    Estudiante.cpp
    DialogoDetalle.h
    DialogoDetalle.cpp
)

target_link_libraries(Ejercicio03
    PRIVATE Qt6::Widgets
)
