#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Sky.h"
#include "Texture.h"
#include "Music.h"
#include "Myplane.h"

int main()
{
    Texture::load();
    Music::load();
    Sky* sky = Sky::getInstance();
    sf::RenderWindow* window = sky->getWindow();
    Music::BACK_GROUND.play();
    Myplane myplane;
    sky->add(&myplane);
    /**
    sf::Font font;
    if (!font.loadFromFile("font/STHeiti Light.ttc"))
        return EXIT_FAILURE;
    sf::Text text("Hello SFML", font, 50);
    */
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
