#ifndef GUN_H
#define GUN_H
#include <iostream>
#include <SFML/Graphics.hpp>


class Plane;

class Gun
{
    public:
        void setOwner(Plane * owner);
        void fire();
    private:
        sf::Vector2f getPosition();
        Plane* owner;
    protected:
};

#endif // GUN_H
