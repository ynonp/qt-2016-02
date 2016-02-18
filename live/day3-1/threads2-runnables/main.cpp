#include "mainwindow.h"
#include <QApplication>
#include "mytask.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    for (int i=0; i <10; i++)
    {
        MyTask *f1 = new MyTask(QString("/tmp/%1").arg(i));
        QThreadPool::globalInstance()->start(f1);
    }


    QThreadPool::globalInstance()->waitForDone();
    return 0;

}
