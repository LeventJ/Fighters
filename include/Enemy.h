#ifndef ENEMY_H
#define ENEMY_H
#include <Plane.h>

class Enemy:public Plane
{
    public:
        Enemy();
        void beam();
        void hit();
        bool isneedClear();
        bool isDead();
    protected:
    private:
        int state = 0;
};

#endif // ENEMY_H
