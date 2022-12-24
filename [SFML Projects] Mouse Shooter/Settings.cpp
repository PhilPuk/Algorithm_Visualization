#include "Settings.h"

void Settings::initVariables(sf::Color menu_color)
{
	this->goBack = false;
	this->Menu_Color = menu_color;

	this->Menu_Navigation_Index = 0;
	this->Navigation_Index_Changed = false;
}

void Settings::initTexts(sf::Font& font, sf::Vector2f textStartPos, float spacingY)
{
	sf::Text baseText("", font, 24);
	baseText.setFillColor(sf::Color::White);
	baseText.setPosition(textStartPos);
	for (int i = 0; i < sizeof(algo_Names) / sizeof(algo_Names[0]); i++)
	{
		baseText.setString(algo_Names[i]);
		this->Texts.push_back(std::make_unique<sf::Text>(baseText));
		this->Texts[i]->setPosition(textStartPos.x, textStartPos.y + spacingY * i);
	}
}

//Menu_Navigation
void Settings::navigateUP()
{
	if (this->Menu_Navigation_Index > 0)
	{
		this->Menu_Navigation_Index--;
		this->Navigation_Index_Changed = true;
	}
}

void Settings::navigateDOWN()
{
	if (this->Menu_Navigation_Index < 3)
	{
		this->Menu_Navigation_Index++;
		this->Navigation_Index_Changed = true;
	}
}

void Settings::navigateWithMouse()
{
	for (int i = 0; i < this->Texts.size(); i++)
	{
		if (this->Texts[i]->getGlobalBounds().contains(this->mouse.getMousePosView()))
		{
			this->Menu_Navigation_Index = i;
			this->Navigation_Index_Changed = true;
		}
	}
}

Settings::Settings(sf::Font& font, sf::Vector2f textStartPos, float spacingY, sf::Color menu_color)
{
	this->initVariables(menu_color);
	this->initTexts(font, textStartPos, spacingY);
}

Settings::~Settings()
{

}

void Settings::run(sf::RenderWindow& window)
{
	while (!this->goBack)
	{
		this->update(window);

		this->render(window);
	}

	this->goBack = false;
}

void Settings::EventEnterPressed(sf::Event& ev)
{
	if (ev.key.code == sf::Keyboard::Enter)
	{
	}
}

void Settings::EventMenuNavigation(sf::Event& ev)
{
	//Menu Navigation Event
	if (ev.key.code == sf::Keyboard::W || ev.key.code == sf::Keyboard::Up)
		this->navigateUP();
	else if (ev.key.code == sf::Keyboard::S || ev.key.code == sf::Keyboard::Down)
		this->navigateDOWN();
}

void Settings::pollEventsKeyPressed(sf::Event& ev)
{
	//Esc to close
	if (ev.key.code == sf::Keyboard::Escape)
		this->goBack = true;

	this->EventEnterPressed(ev);

	this->EventMenuNavigation(ev);
}

void Settings::pollEvents(sf::RenderWindow& window)
{
	sf::Event ev;
	while (window.pollEvent(ev))
	{
		switch (ev.type)
		{
			//Closing Event
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			this->pollEventsKeyPressed(ev);
			break;
		}
	}
}

void Settings::updateText()
{
	//Changes color of currently selected option 
//Resets other to standart color
	if (this->Navigation_Index_Changed)
	{
		for (int i = 0; i < this->Texts.size(); i++)
		{
			if (i == this->Menu_Navigation_Index)
				this->Texts[i]->setFillColor(sf::Color::Magenta);
			else
				this->Texts[i]->setFillColor(this->Menu_Color);
		}
		this->Navigation_Index_Changed = false;
	}
}

void Settings::update(sf::RenderWindow& window)
{
	this->pollEvents(window);

	this->mouse.update(window, false);

	this->navigateWithMouse();

	this->updateText();
}

void Settings::renderTexts(sf::RenderTarget& target)
{
	for (auto& i : this->Texts)
	{
		target.draw(*i);
	}
}

void Settings::render(sf::RenderWindow& window)
{
	window.clear();

	this->renderTexts(window);

	window.display();
}
