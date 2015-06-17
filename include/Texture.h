#ifndef __Fighters__Texture__
#define __Fighters__Texture__

#include <SFML/Graphics.hpp>


class Texture{
public:
    static sf::Texture HERO;
    static sf::Texture HERO_DOWN_1;
    static sf::Texture HERO_DOWN_2;
    static sf::Texture HERO_DOWN_3;

    static sf::Texture ENEMY_SMALL;
    static sf::Texture ENEMY_MIDDLE;
    static sf::Texture ENEMY_BIG;
    static sf::Texture ENEMY_BIG_DOWN_1;
    static sf::Texture ENEMY_BIG_DOWN_2;
    static sf::Texture ENEMY_BIG_DOWN_3;
    static sf::Texture ENEMY_BIG_DOWN_4;
    static sf::Texture ENEMY_DOWN_1;
    static sf::Texture ENEMY_DOWN_2;
    static sf::Texture ENEMY_DOWN_3;
    static sf::Texture ENEMY_DOWN_4;

    static sf::Texture BULLET;
    static sf::Texture BULLET2;

    static sf::Texture SKY;
    static sf::Texture SKY_1;
    static sf::Texture SKY_2;
    static sf::Texture SKY_3;
    static sf::Texture SKY_4;

    static void load();
};

#endif /* defined(__Fighters__Texture__) */
