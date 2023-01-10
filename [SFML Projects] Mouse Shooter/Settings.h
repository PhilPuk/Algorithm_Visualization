#pragma once

#include<iostream>
#include<sstream>
#include<vector>
#include<memory>
#include"Mouse.h"
#include"Button.h"
#include"Generation.h"

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

//Button needs parameters!

class Settings
{
private:
	std::vector<std::unique_ptr<sf::Text>> Texts;
	std::string algo_Names[4] = { "Bubble Sort" ,"Selection Sort", "Insertion Sort", "Merge Sort" };
	
	bool goBack;
	Mouse mouse;

	sf::Color Menu_Color;

	std::unique_ptr<Button()> button;

	//Menu_Navigation
	short Menu_Navigation_Index;
	bool Navigation_Index_Changed;

	void navigateUP();
	void navigateDOWN();
	void navigateWithMouse();

	void initVariables(sf::Color menu_color);
	void initTexts(sf::Font& font, sf::Vector2f textStartPos, float spacingY);
public:
	Settings(sf::Font& font, sf::Vector2f textStartPos, float spacingY, sf::Color menu_color);
	virtual~Settings();

	int selected_Algo;

	void run(sf::RenderWindow& window, Generation& gen);

	void EventEnterPressed(sf::Event& ev);
	void EventMenuNavigation(sf::Event& ev);
	void pollEventsKeyPressed(sf::Event& ev);
	void pollEvents(sf::RenderWindow& window);

	void updateButton(Generation& gen);
	void updateCurrentlySelected(int index);
	void updateText();
	void update(sf::RenderWindow& window, Generation& gen);

	void renderTexts(sf::RenderTarget& target);
	void render(sf::RenderWindow& window);
};

