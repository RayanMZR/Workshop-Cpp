/*
** EPITECH PROJECT, 2024
** Workshop-Cpp
** File description:
** step1
*/

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(440, 592), "Calculatrice");
    sf::Texture texture;
    if (!texture.loadFromFile("utils/sprite_calculator.png"))
        return 84;

    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }
    return 0;
}
