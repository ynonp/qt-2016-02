#include "mainwindow.h"
#include <QApplication>
#include "mytask.h"
#include "counter.h"
#include "countertask.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    Counter c;
    CounterTask *t1 = new CounterTask(c, 1);
    CounterTask *t2 = new CounterTask(c, -1);

    QThreadPool::globalInstance()->start(t1);
    QThreadPool::globalInstance()->start(t2);

    QThreadPool::globalInstance()->waitForDone();

    qDebug() << "Value = " << c.val();
    return 0;

}
