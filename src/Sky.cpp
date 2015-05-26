#include "Sky.h"
#include "Enemy.h"
#include "Texture.h"

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
}

void Sky::collision(){
    for(auto it_enemy= this->enemies.begin();it_enemy!=this->enemies.end();++it_enemy){
        if((*it_enemy)->isDead()) continue;

        for(auto it_bullet= this->bullets.begin();it_bullet!=this->bullets.end();++it_bullet){
            if((*it_enemy)->intersects(*it_bullet)){
                delete *it_bullet;
                this->sprites.erase(*it_bullet);
                (this->bullets).erase(it_bullet);

                (*it_enemy)->hit();
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
void Sky::refresh()
{
    this->window->draw(*this->background);
    this->clear();
    this->collision();
    this->createenemies();
    for(auto &sprite:this->sprites)
    {
        sprite->beam();
        this->window->draw(*sprite);
    }

    this->window->display();
}

