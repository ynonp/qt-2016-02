#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets>
#include <QtGui>
#include "lab.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;
    QVBoxLayout *layout = new QVBoxLayout(&w);

    QLabel *l = new QLabel("Hello World");
    QLabel *t = new QLabel("Hello World");
    QPushButton *btn = new QPushButton("Click");

    Lab lab1;
    Lab lab2;

    QObject::connect(btn, SIGNAL(clicked()),
                     &lab1, SLOT(boom()));


    QObject::connect(btn, SIGNAL(clicked()),
                     &lab2, SLOT(boom()));

    QObject::connect(btn, &QPushButton::clicked,
                     &lab1, &Lab::boom);


    QObject::connect(btn, &QPushButton::clicked,
                     [=] () { qDebug() << "Boom!" });


    layout->addWidget(l);
    layout->addWidget(t);
    layout->addWidget(btn);

    w.show();

    return app.exec();
}









