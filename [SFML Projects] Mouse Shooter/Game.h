#pragma once

#define ARRAY_START_SIZE 60

#include<iostream>
#include<time.h>

#include"Generation.h"
#include"Algorithms.h"
#include"TextureManager.h"


class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::Vector2u winSize;

	//Events
	sf::Event ev;

	//Generation of Array
	Generation* gen;

	//Algorithms
	Algorithms* algo;

	//End logic
	bool endGame;
	bool endApplication;

	bool sortedArrayPrinted;

	void initWindow(sf::RenderWindow* window);
	void initVariables(sf::RenderWindow* window);
	void initGeneration();
	void initAlgorithms(sf::Font& font);
public:
	Game(sf::RenderWindow* window, sf::Font& font);
	virtual ~Game();

	void CloseApplication();
	void resetVariables();

	//Accessors
	const bool& getEndGame() const;
	const bool& getEndApplication() const;

	//Main loop
	void run();

	//Update
	void pollEvents();
	void update();

	//Render
	void render();
};

