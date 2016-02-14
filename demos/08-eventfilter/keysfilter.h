#ifndef KEYSFILTER_H
#define KEYSFILTER_H

#include <QObject>

class KeysFilter : public QObject
{
    Q_OBJECT
public:
    explicit KeysFilter(QObject *parent = 0);

protected:
    bool eventFilter(QObject * watched, QEvent * event);

signals:

public slots:

};

#endif // KEYSFILTER_H
