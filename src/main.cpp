#include <iostream>
#include <stdexcept>
#include <vector>
#include "timer.h"

std::vector<long long> list;
long long fibonacci_dynamic(long f)
{
        // make sure vector is at least as big as the current index
        if ((unsigned)f+1 > list.size())
                list.resize(f+10, -1);

        if (f == 1 || f == 0)
                return list.at(f) = f;

        long min1, min2;

        min1 = list.at(f-1);
        if (min1 == -1)
                min1 = list.at(f-1) = fibonacci_dynamic(f-1);

        min2 = list.at(f-2);
        if (min2 == -1)
                min2 = list.at(f-2) = fibonacci_dynamic(f-2);

        return list.at(f) = min1 + min2;
}

int main(int argc, const char *argv[])
{
        timer t;
        const long MAX_I = 90;

        long last = 0;
        t.start();
        for (int i = 0; i <= MAX_I; ++i) {
                last = fibonacci_dynamic(i);
        }
        t.stop();
        std::cout << "Iterations: " << MAX_I << 
                " Last fib(" << MAX_I << ") = " << last << "\nElapsed: " << t.elapsed_seconds()*1000 << "ms" << std::endl;

        std::cout << "\nNow calculate backwards :)" << std::endl;
        list.clear();
        last = 0;

        t.start();
        for (int i = MAX_I; i >= 0; --i) {
                last = fibonacci_dynamic(i);
        }
        t.stop();
        std::cout << "Iterations: " << MAX_I << 
                " Last fib(" << MAX_I << ") = " << last << "\nElapsed: " << t.elapsed_seconds()*1000 << "ms" << std::endl;

        return 0;
}
