#include "Gun.h"
#include "Sky.h"
#include "Plane.h"
#include "Bullet.h"

void Gun::fire()
{
    sf::Vector2f postion = ((this->owner)->getPosition());
    Bullet* bullet = new Bullet(postion.x,postion.y);
    Sky::getInstance()->add(bullet);
    Sky::getInstance()->addBullet(bullet);
}
void Gun::setOwner(Plane* owner)
{
    this->owner=owner;
}
sf::Vector2f Gun::getPosition()
{
    sf::Vector2f ff;
    return ff;
}


