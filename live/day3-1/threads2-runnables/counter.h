#ifndef COUNTER_H
#define COUNTER_H

#include <QMutex>
#include <QAtomicInt>

class Counter
{
public:
    Counter();

    int val();
    void inc(int delta);

private:
    int m_val;
    QMutex m_lock;
};

#endif // COUNTER_H
