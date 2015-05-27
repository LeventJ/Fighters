#ifndef BOSS_H
#define BOSS_H
#include "Plane.h"

class Boss:public Plane
{
    public:
        Boss();
        void beam();
        void hit();
        bool isneedClear();
        bool isDead();
    protected:
    private:
        int state=0;
        int a=0;
};

#endif // BOSS_H
