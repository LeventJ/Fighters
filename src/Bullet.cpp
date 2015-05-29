#include "Bullet.h"
#include "Texture.h"

Bullet::Bullet(float x,float y)
{
   this->setTexture(Texture::BULLET);
    this->setPosition(x, y);
}

void Bullet::beam()
{
    this->move(0,-1);
}
bool Bullet::isneedclear()
{
    return this->getPosition().y<0;
}



