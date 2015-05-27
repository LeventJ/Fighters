#ifndef ENEMY_H
#define ENEMY_H
#include <Plane.h>

class Enemy2:public Plane
{
    public:
        Enemy2();
        void beam2();
        void hit2();
        bool isneedClear2();
        bool isDead2();
    protected:
    private:
        int state2 = 0;
};

#endif // ENEMY_H
