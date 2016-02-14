#ifndef MYPAINTEDITEM_H
#define MYPAINTEDITEM_H

#include <QtQuick>
#include <QtCore>

class MyPaintedItem : public QQuickPaintedItem
{
    Q_OBJECT

public:    
    MyPaintedItem(QQuickItem *parent = NULL);

    void paint(QPainter *painter);
};

#endif // MYPAINTEDITEM_H
