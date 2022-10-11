#pragma once

#include<iostream>
#include<vector>
#include"BrickManager.h"

class Algorithms
{
private:

	bool algoFinished;

	void initVariables();
	void initBrickManager(sf::Vector2u& winSize, std::vector<int>& array, sf::Font& font, bool UsefullScreen);
public:
	Algorithms(sf::Vector2u& winSize, std::vector<int>& array, sf::Font& font, bool UsefullScreen);
	virtual ~Algorithms();

	//BrickManager
	BrickManager* bricks;

	//Utility
	void setBricksColorRed(int i, int j);
	void setBricksColorBlack(int i, int j);
	void swopTwoInt(int* a, int* b);

	//Algorithms
	void Bubble_Sort(std::vector<int>& array, sf::RenderWindow& window);
	void Selection_Sort(std::vector<int>& array, sf::RenderWindow& window);

	void currentSelectedAlgo(std::vector<int>& array, sf::RenderWindow& window);

	void update(std::vector<int>* array);

	void renderBrickManager(sf::RenderTarget& target);
	void render(sf::RenderWindow& target);
};
