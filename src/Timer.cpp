#include "Timer.h"

void Timer::start () {
    reset();
}

bool Timer::ifTimePassed (unsigned miliseconds) {
    bool retVal = false;

    if(m_endTime - m_startTime >= miliseconds) {
        m_startTime = SDL_GetTicks();
        retVal = true;
    }

    m_endTime = SDL_GetTicks();
    
    return retVal;
}
void Timer::reset () {
    m_startTime = SDL_GetTicks();
    m_endTime = SDL_GetTicks();
}
