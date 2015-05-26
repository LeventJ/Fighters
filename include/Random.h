#ifndef RANDOM_H
#define RANDOM_H
#include <random>
#include <ctime>

class Random
{
    public:
        static Random* getInstance();
        static std::default_random_engine random_engine;
    private:
        static Random* instance;
};

#endif // RANDOM_H
