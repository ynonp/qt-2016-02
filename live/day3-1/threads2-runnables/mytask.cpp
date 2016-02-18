#include "mytask.h"
#include <QtCore>

MyTask::MyTask(QString filename):
    m_filename(filename)
{

}



void MyTask::run()
{
    QFile f(m_filename);
    f.open(QIODevice::WriteOnly);

    f.write("Hello World\n");
    qDebug() << "Finished: " << QThread::currentThreadId();
    f.close();
}
