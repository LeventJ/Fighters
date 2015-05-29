#ifndef BULLET_H
#define BULLET_H
#include "Sprite.h"

class Bullet:public Sprite
{
    public:
        Bullet(float x,float y);
        void beam();
        bool isneedclear();
    protected:
    private:
};

#endif // BULLET_H
