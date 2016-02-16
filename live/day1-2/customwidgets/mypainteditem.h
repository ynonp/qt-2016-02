#ifndef MYPAINTEDITEM_H
#define MYPAINTEDITEM_H

#include <QWidget>

class MyPaintedItem : public QWidget
{
    Q_OBJECT
public:
    explicit MyPaintedItem(QWidget *parent = 0);

signals:

public slots:
    // QWidget interface
public:
    virtual QSize sizeHint() const;

protected:
    virtual void paintEvent(QPaintEvent *);
};

#endif // MYPAINTEDITEM_H
















