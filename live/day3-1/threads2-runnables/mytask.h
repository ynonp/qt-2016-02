#ifndef MYTASK_H
#define MYTASK_H
#include <QtCore>


class MyTask  : public QRunnable
{
public:
    MyTask(QString filename);

    // QRunnable interface
public:
    virtual void run();

private:
    QString m_filename;
};

#endif // MYTASK_H
