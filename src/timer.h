/*
 * A high resolution timer for testing the performance
 * of programs
 */
#include <chrono>

using HRClock = std::chrono::high_resolution_clock;
using SteadyClock = std::chrono::steady_clock;

class timer
{
        public:
                bool is_started();
                bool is_paused();
                double elapsed_seconds();
                void start();
                void stop();
                void pause();
        
        private:
                bool started = false;
                bool paused = false;
                double last_stopped_time_in_s = 0.0;
                double pause_time = 0.0;
                std::chrono::time_point<HRClock> start_time;

                void reset();
};
