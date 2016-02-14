#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget *parent):
    QLabel(parent)
{

}

ClickableLabel::ClickableLabel(QString text, QWidget *parent):
    QLabel(text, parent)
{

}


void ClickableLabel::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        emit clicked();
    }
}

