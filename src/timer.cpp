#include <iostream>
#include "timer.h"

void timer::start()
{
        // init clock
        /* std::cout << std::boolalpha << HRClock::is_steady << std::endl << SteadyClock::is_steady << std::endl; */

        start_time = HRClock::now();

        started = true;
        paused = false;
}

void timer::pause()
{
        if (started && !paused)
        {
                pause_time += elapsed_seconds();
                paused = true;
        }
}

void timer::stop()
{
        last_stopped_time_in_s = elapsed_seconds();
        reset();
}

bool timer::is_started()
{
        return started;
}

bool timer::is_paused()
{
        return paused;
}

double timer::elapsed_seconds()
{
        if (!started)
                return last_stopped_time_in_s;

        auto end = HRClock::now();
        std::chrono::duration<double> diff_in_s = end-start_time;
        double elapsed_t = diff_in_s.count() + pause_time;
        return elapsed_t;

}


void timer::reset()
{
        pause_time = 0;
        paused = false;
        started = false;
}
