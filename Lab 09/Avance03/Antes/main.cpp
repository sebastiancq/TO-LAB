#include <QApplication>
#include "VentanaRegistro.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    VentanaRegistro ventana;
    ventana.show();
    return app.exec();
}
