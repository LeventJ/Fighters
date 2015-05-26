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
    this->move(-10,0);
}
void Myplane::move_right()
{
    this->move(10,0);
}
void Myplane::move_up()
{
    this->move(0,-10);
}
void Myplane::move_down()
{
    this->move(0,10);
}
