#include "Enemy2.h"
#include "Texture.h"
#include "Music.h"
#include "Random.h"
#include <random>
#include <iostream>
using namespace std;

Enemy2::Enemy2()
{
    this->setTexture(Texture::ENEMY2);
    uniform_int_distribution<unsigned> u(0,400);
    std::default_random_engine random_engine;
    this->setPosition(u(Random::random_engine), 20);

    this->gun.setOwner(this);
}
void Enemy2::beam2()
{
    switch(this->state2){
        case 0:
            this->move(0,0.1);
            break;
        case 1:
            this->setTexture(Texture::ENEMY_DOWN_2);
            this->state2++;
            break;
        case 2:
            this->setTexture(Texture::ENEMY_DOWN_3);
            this->state2++;
            break;
        case 3:
            this->setTexture(Texture::ENEMY_DOWN_4);
            this->state2++;
            break;
        default:;
    }
}
void Enemy2::hit2()
{
    this->state2= 1;
    this->setTexture(Texture::ENEMY_DOWN_1);
    Music::ENEMY_DOWN.play();
}
bool Enemy2::isneedClear2()
{
    return this->state2 == 4;
}
bool Enemy2::isDead2()
{
    return this->state2!=0;
}
