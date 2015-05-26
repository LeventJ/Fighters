#ifndef MUSIC_H
#define MUSIC_H
#include <SFML/Audio.hpp>

class Music
{
    public:
        static sf::Music BACK_GROUND;
        static sf::Music ENEMY_DOWN;
        static void load();
    protected:
    private:
};

#endif // MUSIC_H
