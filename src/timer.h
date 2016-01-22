/*
 * A high resolution timer for testing the performance
 * of programs
 */

class timer
{
        public:
                bool is_running();
                bool is_paused();
                void start();
                void stop();
                void pause();
        
        private:
                bool started = false;
                bool paused = false;
};
