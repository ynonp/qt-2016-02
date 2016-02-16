#include "mainwindow.h"
#include <QApplication>
#include "counter.h"
#include "mylabel.h"
#include "mypainteditem.h"
#include "lightbulb.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    MyPaintedItem w;
//    w.show();

    /*
    LightBulb w;
    QPalette pal = a.palette();
    pal.setBrush(QPalette::AlternateBase,
                 Qt::yellow);
    w.setPalette(pal);
    w.show();
    */

    QWidget w;
    QVBoxLayout *l = new QVBoxLayout(&w);

    QPushButton btn;
    btn.setStyleSheet("background-color:yellow; color: green");
    btn.setText("Click Me");
    // btn.show();

    l->addWidget(new QPushButton("normal button"));

    QPushButton *b3 = new QPushButton("third");
    b3->setStyleSheet("color:green");

    l->addWidget(&btn);
    l->addWidget(b3);
    w.show();

    w.setStyleSheet(styleReadFromOutside);

    return a.exec();
}












