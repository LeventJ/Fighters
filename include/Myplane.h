#ifndef MYPLANE_H
#define MYPLANE_H
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
        void move_left_up();
    protected:
    private:
};

#endif // MYPLANE_H
