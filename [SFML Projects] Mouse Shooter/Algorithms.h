#pragma once

#include<iostream>
#include<vector>
#include"BrickManager.h"

#define PAUSE_TIMER 100

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

	void resetAlgoFinished();
	const bool& getAlgoFinished() const;

	//Algorithms
	void Bubble_Sort(std::vector<int>& array, sf::RenderWindow& window);
	void Selection_Sort(std::vector<int>& array, sf::RenderWindow& window);
	//Merge Sort
	void merge(sf::RenderWindow& window, std::vector<int>& array, int left_index, int mid_index, int right_index);

	void Merge_Sort(sf::RenderWindow& window, std::vector<int>& array, int left_index, int right_index);

	void currentSelectedAlgo(std::vector<int>& array, sf::RenderWindow& window);

	void renderBrickManager(sf::RenderTarget& target);
	void render(sf::RenderWindow& target);

	void renderWithBreak(sf::RenderWindow& target, unsigned int milliseconds);
};