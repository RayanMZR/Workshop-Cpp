/*
** EPITECH PROJECT, 2024
** Workshop-Cpp
** File description:
** step2
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(440, 592), "Calculatrice");
    sf::Texture texture;
    if (!texture.loadFromFile("utils/sprite_calculator.png"))
        return 84;

    sf::Sprite sprite;
    sprite.setTexture(texture);

    std::string input_user = "";

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128) {
                    char input = static_cast<char>(event.text.unicode);
                    if (isdigit(input) || input == '+' || input == '-' || input == '*' || input == '/') {
                        input_user += input;
                        std::cout << input_user << std::endl;
                    }
                    else if (input == '\r' || input == '\n') {
                        std::cout << "Result: " << input_user << std::endl;
                        input_user = "";
                    }
                }
            }
        }
        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }
    return 0;
}
