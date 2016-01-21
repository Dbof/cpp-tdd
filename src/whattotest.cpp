#include<cmath>
#include <iostream>
#include <tuple>

#include "whattotest.h"

double squareRoot(const double a)
{
        if (a < 0.0)
                return -1.0;
        return sqrt(a);
}


int test()
{
        auto foo = std::make_tuple("bar", "foo", "can");
        std::cout << std::get<0>(foo) << std::get<1>(foo) << std::get<2>(foo);
} 
