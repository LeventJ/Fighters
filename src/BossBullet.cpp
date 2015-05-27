#include "BossBullet.h"
#include "Texture.h"

BossBullet::BossBullet(float x,float y)
{
    this->setTexture(Texture::BULLET2);
    this->setPosition(x+40, y+100);
}

void BossBullet::boss_beam()
{
    this->move(0,0.1);
}
