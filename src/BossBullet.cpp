#include "BossBullet.h"
#include "Texture.h"

BossBullet::BossBullet(float x,float y)
{
    this->setTexture(Texture::BULLET2);
    this->setPosition(x+80, y+200);
}

void BossBullet::boss_beam()
{
    this->move(0,2);
}

bool BossBullet::isneedclear()
{
    return this->getPosition().y>800;
}
