#include "mainwindow.h"
#include <QApplication>
#include "clickablelabel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClickableLabel l("Hello!");

    QObject::connect(&l, &ClickableLabel::clicked,
                     [=] () { qApp->quit(); });

    l.show();

    return a.exec();
}
