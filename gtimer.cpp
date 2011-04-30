#include "gtimer.h"

GTimer::GTimer(void)
       :isRunning(false),
        isPaused(false),
        myStartTicks(SDL_GetTicks())
        
{    

}

void GTimer::start(void)
{
    isRunning = true;
    myStartTicks = SDL_GetTicks();
}

void GTimer::stop(void)
{
    isRunning = false;
    myStartTicks = 0;
}

void GTimer::pause(void)
{
    isPaused = true;
    myPauseTicks = SDL_GetTicks();
}

void GTimer::unpause(void)
{
    isPaused = false;
    myPauseTicks = 0;
}

Uint32 GTimer::getTicks(void) const
{
    if (!isPaused)
        return SDL_GetTicks() - myStartTicks;
    return myPauseTicks;
}   
