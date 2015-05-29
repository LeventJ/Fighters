#include "Boss.h"
#include "Texture.h"
#include "Music.h"
#include "Random.h"

#include <random>

#include <iostream>
using namespace std;
Boss::Boss()
{
    this->setTexture(Texture::ENEMY_BIG);

    uniform_int_distribution<unsigned> u(0,320);
    std::default_random_engine random_engine;
    this->setPosition(u(Random::random_engine), -400);

    this->gun.setOwner(this);
}

void Boss::beam()
{

    switch(this->state){
        case 0:
            this->move(0,0.04);
            if(this->getPosition().y+100>a){
                this->boss_fire();
                a+=30;
            }
           break;
        case 1:
            this->setTexture(Texture::ENEMY_DOWN_2);
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

void Boss::hit()
{
    this->setTexture(Texture::ENEMY_DOWN_1);
    if(cnt1>7)
    {
    this->state = 1;
    cnt1=0;
    }else{
        cnt1++;
        switch(this->cnt1)
        {
            case 1:
            case 2:
                this->setTexture(Texture::ENEMY_BIG_DOWN_1);
                break;
            case 3:
            case 4:
                this->setTexture(Texture::ENEMY_BIG_DOWN_2);
                break;
            case 5:
            case 6:
                this->setTexture(Texture::ENEMY_BIG_DOWN_3);
                break;
            case 7:
            case 8:
                this->setTexture(Texture::ENEMY_BIG_DOWN_4);
                break;

        }


    }
    Music::ENEMY_DOWN.play();
}

bool Boss::isneedClear()
{
    return (this->state == 4)||(this->getPosition().y>800);
}

bool Boss::isDead(){
    return this->state != 0;
}
