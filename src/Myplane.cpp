#include "Myplane.h"
#include "Texture.h"

Myplane::Myplane()
{
    this->setTexture(Texture::HERO);
    this->setPosition(180, 600);
    this->gun.setOwner(this);
}
void Myplane::move_left()
{
    if(this->getPosition().x>0)
    this->move(-10,0);
}
void Myplane::move_right()
{
    if(this->getPosition().x<380)
    this->move(10,0);
}
void Myplane::move_up()
{
    if(this->getPosition().y>0)
    this->move(0,-10);
}
void Myplane::move_down()
{
    if(this->getPosition().y<680)
    this->move(0,10);
}
