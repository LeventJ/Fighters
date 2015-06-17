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

#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;
class Sky
{
    public:
        static Sky* getInstance();
        sf::RenderWindow* getWindow();
        void add(Sprite *);
        void addmyplane(Sprite*);
        void addBullet(Bullet *);
        void addBossBullet(BossBullet *);
        void refresh();


    protected:
    private:

        Sky();
        sf::RenderWindow* window;
         ///vector<Sprite*> sprites;
        unordered_set<Sprite*> sprites;
        ///vector<Sprite*> sprites;
        unordered_set<Sprite*> myplane;
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

        int n = 0;
        bool control=true;
        //sf::Text text;
        void clear();
        void collision();
        void createenemies();
        void createbosses();
        int m=0;
        void changesky();

};

#endif // SKY_H
