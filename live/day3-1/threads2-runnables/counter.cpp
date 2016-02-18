#include "counter.h"

Counter::Counter():
    m_val(0)
{

}

int Counter::val()
{
    return m_val;
}

void Counter::inc(int delta)
{
    m_lock.lock();
    m_val += delta;
    m_lock.unlock();
}

