#ifndef SKY_H
#define SKY_H
#include <SFML/Graphics.hpp>
#include<vector>
#include "Sprite.h"
#include "Enemy.h"
#include "Bullet.h"
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
        void refresh();


    protected:
    private:
        Sky();
        sf::RenderWindow* window;
         ///vector<Sprite*> sprites;
        unordered_set<Sprite*> sprites;
        ///vector<Enemy*> enemies;
        unordered_set<Enemy*> enemies;
        ///vector<Bullet*> bullets;
        unordered_set<Bullet*> bullets;
        sf::Sprite* background = nullptr;
        static Sky* instance;

        void clear();
        void collision();
        void createenemies();
};

#endif // SKY_H
