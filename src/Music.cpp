#include "Music.h"
#include <SFML/Audio.hpp>

sf::Music Music::BACK_GROUND;
sf::Music Music::ENEMY_DOWN;

void Music::load()
{
    BACK_GROUND.openFromFile("sound/game_music.ogg");
    ENEMY_DOWN.openFromFile("sound/enemy1_down.ogg");
}
