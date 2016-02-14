#include <QtGui>
#include <QtWidgets>
#include "onoffswitch.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    OnOffSwitch w;
    w.setStyleSheet("background:yellow");
    w.show();

    return app.exec();
}
