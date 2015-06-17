#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Sky.h"
#include "Texture.h"
#include "Music.h"
#include "Myplane.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    Texture::load();
    Music::load();
    Sky* sky = Sky::getInstance();
    sf::RenderWindow* window = sky->getWindow();
    //window->setFramerateLimit(1200);
    Music::BACK_GROUND.play();
    Myplane myplane;
    sky->addmyplane(&myplane);
    sf::Clock clock;
    sf::Time time;
    //clock.restart();





    while (window->isOpen())
    {
        // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window->close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
                myplane.move_left();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
                myplane.move_right();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
                myplane.move_up();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
                myplane.move_down();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                myplane.fire();

        }
        sky->refresh();
    }
    return EXIT_SUCCESS;
}
