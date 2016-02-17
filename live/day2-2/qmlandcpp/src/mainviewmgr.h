#ifndef MAINVIEWMGR_H
#define MAINVIEWMGR_H

#include <QObject>

class MainViewMgr : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString appName READ appName CONSTANT)
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)

public:
    explicit MainViewMgr(QObject *parent = 0);

    QString appName();

    int count();
    void setCount(int val);

signals:
    void countChanged(int val);

public slots:
    void inc();


private:
    int m_counter;







};

#endif // MAINVIEWMGR_H
