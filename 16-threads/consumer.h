#ifndef CONSUMER_H
#define CONSUMER_H

#include <QtCore>

class Consumer : public QRunnable
{
public:
    Consumer(QStringList &queue, QMutex &mutex, bool *running);

public:
    virtual void run();

private:
    QStringList &m_queue;
    QMutex &m_mutex;
    bool *m_running;

};

#endif // CONSUMER_H
