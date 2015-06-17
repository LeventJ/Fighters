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
void Sprite::hit()
{
    switch(this->cnt)
    {
    case 0:
        this->setTexture(Texture::HERO_DOWN_1);
        break;
    case 1:
        this->setTexture(Texture::HERO_DOWN_2);
        break;
    case 2:
        this->setTexture(Texture::HERO_DOWN_3);
        break;
    }

    cnt++;
    Music::ENEMY_DOWN.play();
}
