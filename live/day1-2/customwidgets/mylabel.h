#ifndef MYLABEL_H
#define MYLABEL_H

#include <QtWidgets>
#include <QtCore>
#include <QtGui>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QString text, QLabel *parent = 0);

    virtual void mousePressEvent(QMouseEvent *e);

signals:
    void clicked();


public slots:
};

#endif // MYLABEL_H
