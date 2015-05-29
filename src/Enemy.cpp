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

            this->move(0,0.1);
            break;
        case 1:

            this->setTexture(Texture::ENEMY_DOWN_2);
            //while((double)time.asSeconds()>0.1&&(double)time.asSeconds()<1){};
            this->state++;
            break;
        case 2:
            this->setTexture(Texture::ENEMY_DOWN_3);
            this->state++;
            break;
        case 3:
            this->setTexture(Texture::ENEMY_DOWN_4);
            this->state++;
            break;
        default:;
    }
}
void Enemy::hit(sf::Clock clock,sf::Time time)
{
    this->setTexture(Texture::ENEMY_DOWN_1);
    if(cnt>0)
    {
    this->state = 1;
    cnt=0;
    }else{
    this->setTexture(Texture::ENEMY_DOWN_2);
    cnt++;
    }
    Music::ENEMY_DOWN.play();
}
bool Enemy::isneedClear()
{
    return (this->state == 3)||(this->getPosition().y>800);
}
bool Enemy::isDead()
{
    return this->state!=0;
}
