#include "Random.h"

Random::Random() {
    this->seed();
}

void Random::seed() {
    srand(time(NULL));
}

int Random::randint(int min, int max) {
    int range = max - min + 1;
    int output = min + (rand() % range);
    return output;
}
