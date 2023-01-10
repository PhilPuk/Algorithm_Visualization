#pragma once

#include<iostream>
#include<string>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class Button 
{
private:
    sf::RectangleShape shape;
    sf::Text text;
    void initVariables();
    void initButton(sf::Vector2f pos, sf::Vector2f size, sf::Color color);
    void initText(std::string text, sf::Color color, sf::Font& font, sf::Color color_text);
public:
    Button(sf::Vector2f pos, sf::Vector2f size, sf::Color color);
    Button(sf::Vector2f pos, sf::Vector2f size, sf::Color color, std::string text, sf::Font& font, sf::Color color_text);
    virtual~Button();

    const bool& get_Button_Clicked(sf::FloatRect& object) const;

    void renderButton(sf::RenderTarget& target);
    void renderText(sf::RenderTarget& target);
}