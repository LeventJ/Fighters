#ifndef ENEMY_H
#define ENEMY_H
#include <Plane.h>
#include <SFML/Graphics.hpp>
class Enemy:public Plane
{
    public:
        Enemy();
        void beam();
        void hit(sf::Clock,sf::Time);
        bool isneedClear();
        bool isDead();
    protected:
    private:
        int state = 0;
        int cnt=0;
};

#endif // ENEMY_H
