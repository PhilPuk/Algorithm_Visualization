#include "Button.h"

void Button::initVariables()
{

}

void Button::initButton(sf::Vector2f pos, sf::Vector2f size, sf::Color color)
{
    this->shape.setPosition(pos);
    this->shape.setSize(size);
    this->shape.setFillColor(color);
}

void Button::initText(std::string text, sf::Color color_text, sf::Font& font)
{
    this->text.setFont(font);
    this->text.setCharacterSize(24); // Calc over size
    this->text.setFillColor(color_text);
}

Button::Button(sf::Vector2f pos, sf::Vector2f size, sf::Color color)
{
    this->initVariables();
    this->initButton(pos, size,color);
}

Button::Button(sf::Vector2f pos, sf::Vector2f size, sf::Color color, std::string text, sf::Font& font, sf::Color color_text)
{
    this->initVariables();
    this->initButton(pos, size,color);
    this->initText(text, font, color_text);
}

Button::~Button()
{

}


const bool& get_Button_Clicked(sf::FloatRect& object) const
{
    return this->shape.getGlobalBounds().contains(object);
}

void Button::renderButton(sf::RenderTarget& target)
{
    target.draw(this->shape);
}

void Button::renderText(sf::RenderTarget& target)
{
    target.draw(this->text);
}
