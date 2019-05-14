#pragma once

#include <cstdlib>
#include <iostream>

class Random {
public:
    Random();
    void seed();
    int randint(int x, int y);
    float randfloat(float min, float max);
};
