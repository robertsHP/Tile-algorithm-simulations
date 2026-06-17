#ifndef TIMER_H
#define TIMER_H

#include "SDL.h"

// #include "Debug.h"

class Timer {
    private :
        bool m_started;

        Uint32 m_startTime;
        Uint32 m_endTime;
    public :
        Timer () {}

        void start ();
        bool ifTimePassed (unsigned miliseconds);
        void reset ();
};

#endif // TIMER_H
