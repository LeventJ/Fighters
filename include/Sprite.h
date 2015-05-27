#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include <SFML/Graphics.hpp>


class Sprite:public sf::Sprite
{
    public:
        virtual void beam(){};
        virtual void boss_beam(){};
        void draw();
        bool intersects(Sprite* other);
    protected:
    private:
};

#endif // SPRITE_H
