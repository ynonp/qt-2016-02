#ifndef COUNTERTASK_H
#define COUNTERTASK_H
#include <QtCore>

class Counter;
class CounterTask: public QRunnable
{
public:
    CounterTask(Counter &counter, int delta);

    // QRunnable interface
public:
    virtual void run();

private:
    Counter &m_counter;
    int m_delta;
};

#endif // COUNTERTASK_H
