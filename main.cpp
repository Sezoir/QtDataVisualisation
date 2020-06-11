#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Bootloader/Startup.hpp"

int main(int argc, char *argv[])
{
    // Enagle high dpi scaling
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    // Create core application
    QGuiApplication app(argc, argv);

    // Bootload project
    Bootloader::Startup loader;

    // Check roject has been created successfully
    if(loader.getSuccess())
    {
        // Enter main event loop
        return app.exec();
    }

    // Return error
    return -1;
}
