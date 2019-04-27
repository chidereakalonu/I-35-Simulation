#pragma once

#include <cstdlib>
#include <iostream>

class Random {
private:
    // none
public:
    Random();
    void seed();
    int randint(int x, int y);
};
