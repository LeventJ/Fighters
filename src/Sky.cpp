#include "Sky.h"
#include "Enemy.h"
#include "Boss.h"
#include "Texture.h"
#include "Font.h"
#include <SFML/Graphics.hpp>

Sky* Sky::instance = nullptr;

Sky::Sky()
{
    this->window = new sf::RenderWindow(sf::VideoMode(480, 800), L"Fighters");
    this->background = new sf::Sprite(Texture::SKY);
}
Sky* Sky::getInstance()
{
    if(!instance)
    {
        instance = new Sky;
    }
    return instance;
}
sf::RenderWindow* Sky::getWindow()
{
    return this->window;
}

void Sky::add(Sprite* sprite)
{
    //this->sprites.push_back(sprite);
    this->sprites.insert(sprite);
}
void Sky::addBullet(Bullet* bullet)
{
    //this->bullets.push_back(bullet);
    this->bullets.insert(bullet);
}
void Sky::addBossBullet(BossBullet* bossbullet)
{
    //this->bullets.push_back(bullet);
    this->bossbullets.insert(bossbullet);
}
void Sky::clear()
{
    for(auto it_enemy = this->enemies.begin();it_enemy!=enemies.end();)
    {
        if((*it_enemy)->isneedClear()){
                delete *it_enemy;

                this->sprites.erase(*it_enemy);

                it_enemy = (this->enemies).erase(it_enemy);
        }else{
                ++it_enemy;
        }
    }
    for(auto it_boss = this->bosses.begin();it_boss!=bosses.end();)
    {
        if((*it_boss)->isneedClear()){
                delete *it_boss;

                this->sprites.erase(*it_boss);

                it_boss = (this->bosses).erase(it_boss);
        }else{
                ++it_boss;
        }
    }
    for(auto it_bullet = this->bossbullets.begin();it_bullet!=bossbullets.end();)
    {
        if((*it_bullet)->isneedclear()){
                delete *it_bullet;

                this->sprites.erase(*it_bullet);

                it_bullet = (this->bossbullets).erase(it_bullet);
        }else{
                ++it_bullet;
        }
    }
    for(auto it_bullet = this->bullets.begin();it_bullet!=bullets.end();)
    {
        if((*it_bullet)->isneedclear()){
                delete *it_bullet;

                this->sprites.erase(*it_bullet);

                it_bullet = (this->bullets).erase(it_bullet);
        }else{
                ++it_bullet;
        }
    }
}

void Sky::collision(sf::Clock clock,sf::Time time){
    for(auto it_enemy= this->enemies.begin();it_enemy!=this->enemies.end();++it_enemy){
        if((*it_enemy)->isDead()) continue;

        for(auto it_bullet= this->bullets.begin();it_bullet!=this->bullets.end();++it_bullet){
            if((*it_enemy)->intersects(*it_bullet)){
                delete *it_bullet;
                this->sprites.erase(*it_bullet);
                (this->bullets).erase(it_bullet);

                (*it_enemy)->hit(clock,time);
                break;
            }
        }
    }
    for(auto it_boss= this->bosses.begin();it_boss!=this->bosses.end();++it_boss){
        if((*it_boss)->isDead()) continue;

        for(auto it_bullet= this->bullets.begin();it_bullet!=this->bullets.end();++it_bullet){
            if((*it_boss)->intersects(*it_bullet)){
                delete *it_bullet;
                this->sprites.erase(*it_bullet);
                (this->bullets).erase(it_bullet);
                (*it_boss)->hit();
                break;
            }
        }
    }
}

void Sky::createenemies()
{
    static int cnt = 0;
    if(++cnt>=1000)
    {
        Enemy* enemy = new Enemy;
        //this->sprites.push_back(enemy);
        this->sprites.insert(enemy);
        //this->enemies.push_back(enemy);
        this->enemies.insert(enemy);
        cnt=0;
    }
}
void Sky::createbosses()
{
    static int cnt2 = 0;
    if(++cnt2>=10000)
    {
        Boss* boss = new Boss;

        //this->sprites.push_back(enemy);
        this->sprites.insert(boss);
        //this->enemies.push_back(enemy);
        this->bosses.insert(boss);

        //boss->boss_fire();
        cnt2=0;
    }
}
void Sky::refresh(sf::Clock clock,sf::Time time,sf::Text text)
{
    this->window->draw(*this->background);
    this->window->draw(text);
    this->clear();
    this->collision(clock,time);
    this->createenemies();
    this->createbosses();
    for(auto &sprite:this->sprites)
    {

        sprite->beam();

        sprite->boss_beam();
        this->window->draw(*sprite);
    }



    this->window->display();
}

