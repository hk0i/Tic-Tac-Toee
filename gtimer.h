#ifndef _GTIMER_H
#define _GTIMER_H

#include "SDL.h"

class GTimer
{
    public:

        GTimer(void);

        void start(void);
        void stop(void);

        void pause(void);
        void unpause(void);

        Uint32 getTicks(void) const;

    private:

        // whether the timer is running or not
        bool isRunning;
        // keep track if it's paused
        bool isPaused;
        // the value of SDL_GetTicks() when the timer is started.
        Uint32 myStartTicks;
        Uint32 myPauseTicks; 

};

#endif
