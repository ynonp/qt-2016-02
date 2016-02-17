#include <QApplication>
#include "startup.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Startup startup;

    return app.exec();
}

