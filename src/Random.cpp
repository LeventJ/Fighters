#include "Random.h"

Random* Random::instance = nullptr;
std::default_random_engine Random::random_engine(time(0));

Random* Random::getInstance()
{
    if(!instance)
    {
        instance = new Random;
    }
    return instance;
}
