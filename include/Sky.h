#ifndef SKY_H
#define SKY_H
#include <SFML/Graphics.hpp>
#include<vector>
#include "Sprite.h"
#include "Enemy.h"
#include "Bullet.h"
#include "BossBullet.h"
#include "Boss.h"
#include <iostream>
#include <unordered_set>
using namespace std;
class Sky
{
    public:
        static Sky* getInstance();
        sf::RenderWindow* getWindow();
        void add(Sprite *);
        void addBullet(Bullet *);
        void addBossBullet(BossBullet *);
        void refresh(sf::Clock,sf::Time,sf::Text);


    protected:
    private:
        Sky();
        sf::RenderWindow* window;
         ///vector<Sprite*> sprites;
        unordered_set<Sprite*> sprites;
        ///vector<Enemy*> enemies;
        unordered_set<Enemy*> enemies;
        ///vector<Boss*> bosses;
        unordered_set<Boss*> bosses;
        ///vector<Bullet*> bullets;
        unordered_set<Bullet*> bullets;
         ///vector<Bullet*> bullets;
        unordered_set<BossBullet*> bossbullets;

        sf::Sprite* background = nullptr;
        sf::Text* scores = nullptr;
        static Sky* instance;

        void clear();
        void collision(sf::Clock,sf::Time);
        void createenemies();
        void createbosses();

};

#endif // SKY_H
