#ifndef BOSSBULLET_H
#define BOSSBULLET_H
#include "Sprite.h"

class BossBullet:public Sprite
{
    public:
        BossBullet(float x,float y);
        void boss_beam();
        bool isneedclear();
    protected:
    private:
};

#endif // BOSSBULLET_H
