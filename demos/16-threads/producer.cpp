#include "producer.h"

Producer::Producer(QStringList &queue, QMutex &mutex, int producerId, bool *running):
    m_queue(queue),
    m_mutex(mutex),
    m_producerId(producerId),
    m_running(running)
{

}


void Producer::run()
{
    qDebug() << "Starting Producer " << m_producerId;

    while (*m_running)
    {
        m_mutex.lock();
        m_queue.append("Product: " + QString::number(m_producerId));
        m_mutex.unlock();
    }
}
