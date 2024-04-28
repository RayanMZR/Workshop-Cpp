/*
** EPITECH PROJECT, 2024
** Workshop-Cpp
** File description:
** step4
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <limits>

double calculate(const std::string& input)
{
    std::istringstream iss(input);
    double a, b;
    char operation;
    iss >> a >> operation >> b;

    switch (operation) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
    return 0;
}

void loop_sfml(sf::RenderWindow& window, sf::Sprite& sprite, sf::Text& text, std::string& input_user)
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128) {
                    char entered = static_cast<char>(event.text.unicode);
                    if (isdigit(entered) || entered == '+' || entered == '-' || entered == '*' || entered == '/' || entered == '.') {
                        input_user += entered;
                        text.setString(input_user);
                    } else if (entered == '\r' || entered == '\n') {
                        double result = calculate(input_user);
                        std::ostringstream ss;
                        ss << result;
                        text.setString(ss.str());
                        input_user = "";
                    }
                }
            }
        }
        window.clear(sf::Color::White);
        window.draw(sprite);
        window.draw(text);
        window.display();
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(440, 592), "Calculatrice");
    sf::Texture texture;
    if (!texture.loadFromFile("utils/sprite_calculator.png"))
        return 84;

    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Font font;
    if (!font.loadFromFile("utils/digital.ttf"))
        return 84;

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(80);
    text.setFillColor(sf::Color::Black);
    text.setPosition(45, 35);

    std::string input_user = "";

    loop_sfml(window, sprite, text, input_user);
    return 0;
}
