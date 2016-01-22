#include "timer.h"

void timer::start()
{
        started = true;
        paused = false;
}

void timer::pause()
{
        paused = true;
}

void timer::stop()
{
        started = false;
}

bool timer::is_running()
{
        return started;
}

bool timer::is_paused()
{
        return paused;
}
