#include "Font.h"
#include <SFML/Audio.hpp>

sf::Font Font::SCORES;

void Font::load()
{
    SCORES.loadFromFile("font/STHeiti Light.ttc");
}
