#include "Texture.h"

sf::Texture Texture::HERO;
sf::Texture Texture::HERO_DOWN_1;
sf::Texture Texture::HERO_DOWN_2;
sf::Texture Texture::HERO_DOWN_3;

sf::Texture Texture::ENEMY_SMALL;
sf::Texture Texture::ENEMY_MIDDLE;
sf::Texture Texture::ENEMY_BIG;
sf::Texture Texture::ENEMY_BIG_DOWN_1;
sf::Texture Texture::ENEMY_BIG_DOWN_2;
sf::Texture Texture::ENEMY_BIG_DOWN_3;
sf::Texture Texture::ENEMY_BIG_DOWN_4;
sf::Texture Texture::ENEMY_DOWN_1;
sf::Texture Texture::ENEMY_DOWN_2;
sf::Texture Texture::ENEMY_DOWN_3;
sf::Texture Texture::ENEMY_DOWN_4;

sf::Texture Texture::BULLET;
sf::Texture Texture::BULLET2;

sf::Texture Texture::SKY;
sf::Texture Texture::SKY_1;
sf::Texture Texture::SKY_2;
sf::Texture Texture::SKY_3;
sf::Texture Texture::SKY_4;

void Texture::load(){
    std::string path ="image/shoot.png";

    HERO.loadFromFile(path, sf::IntRect(0, 99, 102, 126));
    HERO_DOWN_1.loadFromFile(path, sf::IntRect(330, 624, 102, 126));
    HERO_DOWN_2.loadFromFile(path, sf::IntRect(330, 498, 102, 126));
    HERO_DOWN_3.loadFromFile(path, sf::IntRect(430, 624, 102, 126));

    ENEMY_SMALL.loadFromFile(path, sf::IntRect(534, 612, 57, 43));
    ENEMY_MIDDLE.loadFromFile(path, sf::IntRect(0, 10, 68, 80));

    ENEMY_BIG.loadFromFile(path, sf::IntRect(335, 750, 169, 258));
    ENEMY_BIG_DOWN_1.loadFromFile(path, sf::IntRect(0, 486, 160, 258));
    ENEMY_BIG_DOWN_2.loadFromFile(path, sf::IntRect(0, 225, 160, 258));
    ENEMY_BIG_DOWN_3.loadFromFile(path, sf::IntRect(839, 747, 160, 258));
    ENEMY_BIG_DOWN_4.loadFromFile(path, sf::IntRect(165, 486, 160, 258));
    ENEMY_DOWN_1.loadFromFile(path, sf::IntRect(267, 347, 57, 51));
    ENEMY_DOWN_2.loadFromFile(path, sf::IntRect(873, 697, 57, 51));
    ENEMY_DOWN_3.loadFromFile(path, sf::IntRect(267, 296, 57, 51));
    ENEMY_DOWN_4.loadFromFile(path, sf::IntRect(930, 697, 57, 51));

    BULLET.loadFromFile(path, sf::IntRect(1004, 987, 9, 21));
    BULLET2.loadFromFile(path, sf::IntRect(69, 78, 9, 21));

    SKY.loadFromFile("image/background.png");
    SKY_1.loadFromFile("image/background_1.png");
    SKY_2.loadFromFile("image/background_2.png");
    SKY_3.loadFromFile("image/background_3.png");
    SKY_4.loadFromFile("image/gameover.png");
}
