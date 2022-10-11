#include "Brick.h"

void Brick::initVariables()
{

}

void Brick::initShape(sf::Vector2f& pos, sf::Vector2f& size)
{
	this->shape.setFillColor(sf::Color::White);
	this->shape.setOutlineColor(sf::Color::Black);
	this->shape.setOutlineThickness(2.f);

	this->shape.setSize(size);

	//Center Origin
	this->shape.setOrigin
	(
		this->shape.getLocalBounds().left + this->shape.getLocalBounds().width / 2.0f,
		this->shape.getLocalBounds().top + this->shape.getLocalBounds().height / 2.0f
	);

	this->shape.setPosition(pos);
}

void Brick::initText(sf::Font& font, sf::Vector2f& pos)
{
	this->text.setFont(font);
	this->text.setFillColor(sf::Color::Black);
	this->text.setCharacterSize(20);

	this->text.setOrigin
	(
		this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2.0f,
		this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2.0f
	);
	
	this->text.setPosition(sf::Vector2f(pos.x - this->shape.getGlobalBounds().width / 2.f, pos.y - this->shape.getGlobalBounds().height / 2.f));
}

Brick::Brick(sf::Font& font, sf::Vector2f& pos, sf::Vector2f& size)
{
	this->initVariables();
	this->initShape(pos, size);
	this->initText(font, pos);
}

Brick::~Brick()
{

}

void Brick::setTextString(std::string text)
{
	this->text.setString(text);
}

void Brick::setTextInt(int textNumber)
{
	std::stringstream ss;
	ss << textNumber;

	this->text.setString(ss.str());
}

void Brick::update()
{

}

void Brick::renderBrick(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

void Brick::renderText(sf::RenderTarget& target)
{
	target.draw(this->text);
}

void Brick::render(sf::RenderTarget& target)
{
	this->renderBrick(target);
	this->renderText(target);
}
