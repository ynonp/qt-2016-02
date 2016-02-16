#include "lab.h"
#include <QDebug>

Lab::Lab(QObject *parent) : QObject(parent)
{

}

void Lab::boom()
{
    qDebug() << "Boom!";
}

