#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Sprite.h>
#include "Texture.h"
#include "Music.h"


class Sprite:public sf::Sprite
{
    public:
        virtual void beam(){};
        virtual void boss_beam(){};
        void draw();
        void hit();
        bool intersects(Sprite* other);
    protected:
    private:
        int cnt=0;
};

#endif // SPRITE_H
