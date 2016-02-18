#include "countertask.h"
#include "counter.h"

CounterTask::CounterTask(Counter &counter, int delta):
    m_counter(counter),
    m_delta(delta)
{

}



void CounterTask::run()
{
    for ( int i=0; i < 100000000; i++)
    {
        m_counter.inc(m_delta);
    }

}
