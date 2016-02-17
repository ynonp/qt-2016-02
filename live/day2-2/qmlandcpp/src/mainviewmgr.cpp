#include "mainviewmgr.h"
#include <QDebug>

MainViewMgr::MainViewMgr(QObject *parent) :
    QObject(parent),
    m_counter(0)
{

}

QString MainViewMgr::appName()
{
    return "QtQuick Starter 1.0.0";
}

int MainViewMgr::count()
{
    return m_counter;
}

void MainViewMgr::setCount(int val)
{
    m_counter = val;
    emit countChanged(val);
}

void MainViewMgr::inc()
{
    setCount(m_counter+1);
}










