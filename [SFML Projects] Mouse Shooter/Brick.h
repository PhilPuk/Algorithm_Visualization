#pragma once

#include<iostream>
#include<sstream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class Brick
{
private:

	void initVariables();
	void initShape(sf::Vector2f& pos, sf::Vector2f& size);
	void initText(sf::Font& font, sf::Vector2f& pos);
public:
	Brick(sf::Font& font, sf::Vector2f& pos, sf::Vector2f& size);
	virtual ~Brick();

	sf::RectangleShape shape;
	sf::Text text;

	void setTextString(std::string text);
	void setTextInt(int textNumber);
	void update();

	void renderBrick(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

