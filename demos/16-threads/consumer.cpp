#include "consumer.h"

Consumer::Consumer(QStringList &queue, QMutex &mutex, bool *running):
    m_queue(queue),
    m_mutex(mutex),
    m_running(running)
{

}

void Consumer::run()
{
    qDebug() << "Starting New Consumer";
    while(*m_running)
    {
        QString val;
        m_mutex.lock();
        if (!m_queue.isEmpty())
        {
            val = m_queue.takeFirst();
        }
        m_mutex.unlock();

        if (! val.isEmpty())
        {
            //qDebug() << val;
        }

    }
}









