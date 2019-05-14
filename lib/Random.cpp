#include "Random.h"

Random::Random() {
    this->seed();
}

void Random::seed(void) {
    srand((unsigned) time(0));
}

int Random::randint(int min, int max) {
    int range = max - min + 1;
    int output = min + (rand() % range);
    return output;
}

float Random::randfloat(float min, float max) {
    return  (max - min) * ((((float) rand()) / (float) RAND_MAX)) + min;
}
