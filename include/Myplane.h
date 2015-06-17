#ifndef MYPLANE_H
#define MYPLANE_H
#include <Plane.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Plane.h>

class Myplane:public Plane
{
    public:
        Myplane();
        void move_left();
        void move_right();
        void move_up();
        void move_down();
        void hit();
    protected:
    private:
        int cnt=0;
};

#endif // MYPLANE_H
