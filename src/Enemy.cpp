#include "Enemy.h"
#include "Texture.h"
#include "Music.h"
#include "Random.h"
#include <random>
#include <iostream>
using namespace std;

Enemy::Enemy()
{
    this->setTexture(Texture::ENEMY_SMALL);
    uniform_int_distribution<unsigned> u(0,400);
    std::default_random_engine random_engine;
    this->setPosition(u(Random::random_engine), 20);
    this->gun.setOwner(this);
}
void Enemy::beam()
{


    switch(this->state){
        case 0:

            this->move(0,1);
            break;
        case 1:
        case 2:
        case 3:
            this->setTexture(Texture::ENEMY_DOWN_2);
            //while((double)time.asSeconds()>0.1&&(double)time.asSeconds()<1){};
            this->state++;
            break;
        case 4:
        case 5:
        case 6:
            this->setTexture(Texture::ENEMY_DOWN_3);
            this->state++;
            break;
        case 7:
        case 8:
        case 9:
            this->setTexture(Texture::ENEMY_DOWN_4);
            this->state++;
            break;
        default:;
    }
}
void Enemy::hit()
{
    this->setTexture(Texture::ENEMY_DOWN_1);
    state++;
    Music::ENEMY_DOWN.play();
}
bool Enemy::isneedClear()
{
    return (this->state == 10)||(this->getPosition().y>800);
}
bool Enemy::isDead()
{
    return this->state!=0;
}
