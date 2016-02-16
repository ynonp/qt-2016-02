#include "mypainteditem.h"
#include <QtGui>

MyPaintedItem::MyPaintedItem(QWidget *parent) : QWidget(parent)
{

}


QSize MyPaintedItem::sizeHint() const
{
    return QSize(60, 60);
}

void MyPaintedItem::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.fillRect(
                rect().adjusted(10, 10, -10, -10),
                Qt::red);

    painter.fillRect(
                rect().adjusted(20, 20, -20, -20),
                Qt::blue);

}














