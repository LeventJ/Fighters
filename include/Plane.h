#ifndef PLANE_H
#define PLANE_H
#include <SFML/Graphics.hpp>
#include "Gun.h"
#include "Sprite.h"
#include <iostream>
using namespace std;

class Plane:public Sprite
{
    public:
        void fire();
    protected:
        Gun gun;
    private:
};

#endif // PLANE_H
