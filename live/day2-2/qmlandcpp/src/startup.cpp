#include "startup.h"
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "mainviewmgr.h"


Startup::Startup(QObject *parent) :
    QObject(parent),
    m_engine(*new QQmlApplicationEngine(this)),
    m_viewMgr(*new MainViewMgr(this))
{
    m_engine.load(QUrl(QStringLiteral("qrc:/mouse.qml")));
    m_engine.rootContext()->setContextProperty("MainViewMgr",
                                               &m_viewMgr);
}










