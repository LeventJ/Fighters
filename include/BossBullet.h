#ifndef BOSSBULLET_H
#define BOSSBULLET_H
#include "Sprite.h"

class BossBullet:public Sprite
{
    public:
        BossBullet(float x,float y);
        void boss_beam();
    protected:
    private:
};

#endif // BOSSBULLET_H
