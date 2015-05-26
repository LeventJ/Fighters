#include "Sprite.h"
#include "Sky.h"


void Sprite::draw()
{
    Sky::getInstance()->getWindow()->draw(*this);
}
bool Sprite::intersects(Sprite* other)
{
    return this->getGlobalBounds().intersects(other->getGlobalBounds());
}

