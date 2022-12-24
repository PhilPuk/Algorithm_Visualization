#pragma once

#include<iostream>
#include<string>

#include"Mouse.h"
#include"Game.h"
#include"Settings.h"

class Menu
{
private:
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	std::string Application_Title;
	int Framerate;

	//Fonts
	sf::Font font;

	//Texts
	sf::Text Text_Title;
	sf::Text Text_Menu_Options[3];
	sf::Color Color_Menu;
	sf::Vector2f Vector_Menu_Pos;
	float Spacing_Menu_Pos_Y;

	//Menu_Navigation
	short Menu_Navigation_Index;
	bool Navigation_Index_Changed;

	//Game
	Game* game;

	std::unique_ptr<Settings> settings;

	//Private functions
		//Menu_Navigation
	void navigateUP();
	void navigateDOWN();
	void navigateWithMouse();
	 
		//Initilalization
	void initVariables();
	void initWindow();
	void initFonts();
	void initText();
	void initGame();
	std::unique_ptr<Settings> initSettings();

	//Mouse
	Mouse mouse;
public:
	//Constructor / Destructor
	Menu();
	~Menu();

	//Poll Event main functions
	void pollGame();
	void pollSettings();
	void pollStop();
	void pollMainActions();

	//Functions
	void run();
	void EventEnterPressed(sf::Event& ev);
	void EventMenuNavigation(sf::Event& ev);
	void pollEventsKeyPressed(sf::Event& ev);
	void pollEvents();
		//update
	void updateText();
	void udpate();
		//render
	void renderText();
	void render();
};

