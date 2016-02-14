#include "mypainteditem.h"
#include <QtGui>
#include <QtQuick>

MyPaintedItem::MyPaintedItem(QQuickItem *parent):
    QQuickPaintedItem(parent)
{

}


void MyPaintedItem::paint(QPainter *painter)
{
    painter->fillRect(boundingRect().adjusted(10, 10, -10, -10), Qt::yellow);
    painter->fillRect(boundingRect().adjusted(20, 20, -20, -20), QBrush(QColor("orange")));
}

