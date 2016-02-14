#ifndef PRODUCER_H
#define PRODUCER_H

#include <QtCore>

class Producer : public QRunnable
{
public:
    Producer(QStringList &queue, QMutex &mutex, int producerId, bool *running);

    // QRunnable interface
public:
    virtual void run();

private:
    QStringList &m_queue;
    QMutex &m_mutex;
    int m_producerId;
    bool *m_running;
};

#endif // PRODUCER_H
