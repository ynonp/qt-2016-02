#include "mylabel.h"

MyLabel::MyLabel(QString text, QLabel *parent) :
    QLabel(text, parent)
{

}


void MyLabel::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "Mouse Press: " << e;
    emit clicked();
}
