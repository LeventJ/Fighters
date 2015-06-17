#ifndef SCORES_H
#define SCORES_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Font.h"

class Scores:public sf::Text
{
    public:
        Scores();
    protected:
    private:
        sf::Font font;
        sf::Text text;
};

#endif // SCORES_H
