#ifndef LAB_H
#define LAB_H

#include <QObject>

class Lab : public QObject
{
    Q_OBJECT
public:
    explicit Lab(QObject *parent = 0);

    void go();

signals:
    void yo();

private slots:
    void boom();

};

#endif // LAB_H




