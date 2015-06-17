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
    this->background = new sf::Sprite(Texture::SKY_1);
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
void Sky::addmyplane(Sprite* sprite)
{
    //this->sprites.push_back(sprite);
    this->myplane.insert(sprite);
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
                n=n+100;
                delete *it_enemy;

                this->sprites.erase(*it_enemy);
                this->myplane.erase(*it_enemy);
                it_enemy = (this->enemies).erase(it_enemy);
        }else{
                ++it_enemy;
        }
    }
    for(auto it_boss = this->bosses.begin();it_boss!=bosses.end();)
    {
        if((*it_boss)->isneedClear()){
                delete *it_boss;
                n=n+500;
                this->sprites.erase(*it_boss);
                this->myplane.erase(*it_boss);
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
                this->myplane.erase(*it_bullet);
                it_bullet = (this->bossbullets).erase(it_bullet);
        }else{
                ++it_bullet;
        }
    }
    for(auto it_bullet = this->bullets.begin();it_bullet!=bullets.end();)
    {
        if((*it_bullet)->isneedclear()){
                delete *it_bullet;
                this->myplane.erase(*it_bullet);
                this->sprites.erase(*it_bullet);

                it_bullet = (this->bullets).erase(it_bullet);
        }else{
                ++it_bullet;
        }
    }
}

void Sky::collision(){
    for(auto it_enemy= this->enemies.begin();it_enemy!=this->enemies.end();++it_enemy){
        if((*it_enemy)->isDead()) continue;

        for(auto it_bullet= this->bullets.begin();it_bullet!=this->bullets.end();++it_bullet){
            if((*it_enemy)->intersects(*it_bullet)){
                delete *it_bullet;
                this->sprites.erase(*it_bullet);
                this->myplane.erase(*it_bullet);
                (this->bullets).erase(it_bullet);

                (*it_enemy)->hit();
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
                this->myplane.erase(*it_bullet);
                (this->bullets).erase(it_bullet);
                (*it_boss)->hit();
                break;
            }
        }
    }

    for(auto it_hero= this->myplane.begin();it_hero!=this->myplane.end();++it_hero){
        for(auto it_bullet= this->bossbullets.begin();it_bullet!=this->bossbullets.end();++it_bullet){
            if((*it_hero)->intersects(*it_bullet)){
                delete *it_bullet;
                this->sprites.erase(*it_bullet);
                this->myplane.erase(*it_bullet);
                (this->bossbullets).erase(it_bullet);
                (*it_hero)->hit();
                changesky();
                break;
            }
        }
    }

    for(auto it_hero= this->myplane.begin();it_hero!=this->myplane.end();++it_hero){
        for(auto it_enemy= this->enemies.begin();it_enemy!=this->enemies.end();++it_enemy){
            if((*it_hero)->intersects(*it_enemy)){
                delete *it_enemy;
                this->sprites.erase(*it_enemy);
                this->myplane.erase(*it_enemy);
                (this->enemies).erase(it_enemy);
                (*it_hero)->hit();
                changesky();
                break;
            }
        }
    }
    for(auto it_hero= this->myplane.begin();it_hero!=this->myplane.end();++it_hero){
        for(auto it_enemy= this->bosses.begin();it_enemy!=this->bosses.end();++it_enemy){
            if((*it_hero)->intersects(*it_enemy)){
                delete *it_enemy;
                this->sprites.erase(*it_enemy);
                this->myplane.erase(*it_enemy);
                (this->bosses).erase(it_enemy);
                (*it_hero)->hit();
               changesky();
                break;
            }
        }
    }
}

void Sky::createenemies()
{
    static int cnt = 0;
    if(++cnt>=100)
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
    if(++cnt2>=1000)
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

void Sky::changesky(){
    switch (m){
                case 0:
                this->background = new sf::Sprite(Texture::SKY_2);
                    break;
                case 1:
                this->background = new sf::Sprite(Texture::SKY_3);
                    break;
                case 2:
                this->background = new sf::Sprite(Texture::SKY_4);
                control = false;
                    break;

                }
                m++;

}

void Sky::refresh()
{

    this->window->draw(*this->background);
    std::stringstream ss;
    std::string str;
    ss<<n;
    ss>>str;
    sf::Font font;
    font.loadFromFile("font/STHeiti Light.ttc");
    sf::Text text("SCORES :"+str, font, 30);
    this->window->draw(text);
    this->clear();
    if(control)
    {
        this->collision();
        this->createenemies();
        this->createbosses();
        for(auto &sprite:this->myplane)
        {
            this->window->draw(*sprite);
        }
        for(auto &sprite:this->sprites)
        {
            sprite->beam();
            sprite->boss_beam();
            this->window->draw(*sprite);
        }
    }
    this->window->display();
}

