#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>
class QQmlApplicationEngine;
class MainViewMgr;

class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup(QObject *parent = 0);

signals:

public slots:
private:
    QQmlApplicationEngine &m_engine;
    MainViewMgr &m_viewMgr;
};

#endif // STARTUP_H
