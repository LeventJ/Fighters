#include "Font.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

sf::Font Font::SCORES;

void Font::load
{
    SCORES.loadFromFile("font/STHeiti Light.ttc");
}
