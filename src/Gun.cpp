#include "Gun.h"
#include "Sky.h"
#include "Plane.h"
#include "Bullet.h"
#include "BossBullet.h"

void Gun::fire()
{
    sf::Vector2f postion = ((this->owner)->getPosition());
    Bullet* bullet1 = new Bullet(postion.x+10,postion.y);
    Bullet* bullet2 = new Bullet(postion.x+80,postion.y);
    Sky::getInstance()->add(bullet1);
    Sky::getInstance()->addBullet(bullet1);
    Sky::getInstance()->add(bullet2);
    Sky::getInstance()->addBullet(bullet2);

}
void Gun::boss_fire()
{
    sf::Vector2f postion = ((this->owner)->getPosition());
    BossBullet* bullet = new BossBullet(postion.x,postion.y);
    Sky::getInstance()->add(bullet);
    Sky::getInstance()->addBossBullet(bullet);
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


