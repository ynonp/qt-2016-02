#include "keysfilter.h"
#include <QDebug>
#include <QtGui>

KeysFilter::KeysFilter(QObject *parent) :
    QObject(parent)
{
}

bool KeysFilter::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *ev = (QKeyEvent *)event;
        if (ev->key() == Qt::Key_Tab)
        {
            for (int i=0; i<4; i++)
            {
                QKeyEvent *k = new QKeyEvent(QEvent::KeyPress, Qt::Key_Space, Qt::NoModifier, " ");
                qApp->sendEvent(watched, k);
            }
            return true;
        }
    }


    return QObject::eventFilter(watched, event);
}
