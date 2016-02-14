#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H
#include <QLabel>
#include <QtGui>

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    ClickableLabel(QWidget *parent = NULL);
    ClickableLabel(QString text, QWidget *parent = NULL);

protected:
    void mousePressEvent(QMouseEvent *e);

signals:
    void clicked();

};

#endif // CLICKABLELABEL_H
