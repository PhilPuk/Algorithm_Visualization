#include "Algorithms.h"

void Algorithms::initVariables()
{
	this->algoFinished = false;
}

void Algorithms::initBrickManager(sf::Vector2u& winSize, std::vector<int>& array, sf::Font& font, bool UsefullScreen)
{
	this->bricks = new BrickManager(winSize, array, font, true);
}

Algorithms::Algorithms(sf::Vector2u& winSize, std::vector<int>& array, sf::Font& font, bool UsefullScreen)
{
	this->initVariables();
	this->initBrickManager(winSize, array, font, UsefullScreen);
}

Algorithms::~Algorithms()
{
	delete this->bricks;
}

void Algorithms::setBricksColorRed(int i, int j)
{
	this->bricks->bricks[i]->shape.setOutlineColor(sf::Color::Red);
	this->bricks->bricks[j]->shape.setOutlineColor(sf::Color::Red);
}

void Algorithms::setBricksColorBlack(int i, int j)
{
	this->bricks->bricks[i]->shape.setOutlineColor(sf::Color::Black);
	this->bricks->bricks[j]->shape.setOutlineColor(sf::Color::Black);
}

void Algorithms::swopTwoInt(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Algorithms::Bubble_Sort(std::vector<int>& array, sf::RenderWindow& window)
{
	if (!this->algoFinished)
	{
		for (int i = 0; i < array.size(); i++)
		{
			for (int j = i + 1; j < array.size(); j++)
			{
				if (array[i] > array[j])
				{
					//Swop values
					int tmp = array[i];
					array[i] = array[j];
					array[j] = tmp;

					//Set the text to the new values.
					this->bricks->bricks[i]->setTextInt(array[i]);
					this->bricks->bricks[j]->setTextInt(array[j]);
					//Color current compared bricks red.
					this->setBricksColorRed(i, j);

					//Render it to the window
					this->render(window);
					sf::sleep(sf::milliseconds(300));
				}
				//Reset last compared bricks to color black
				this->setBricksColorBlack(i, j);
			}
		}
		this->algoFinished = true;
	}
}

void Algorithms::Selection_Sort(std::vector<int>& array, sf::RenderWindow& window)
{
	if (!algoFinished)
	{
		//First element of array is the min number in the beginning, that doesn't has to be true, it's just for comparsion.

		for (int i = 0; i < array.size() - 1; i++)
		{
			int min_i = i;
			for (int j = i + 1; j < array.size(); j++)
			{
				this->setBricksColorRed(min_i, j);
				if (array[min_i] > array[j])
				{
					this->bricks->bricks[min_i]->shape.setOutlineColor(sf::Color::Black);
					min_i = j;
					this->bricks->bricks[min_i]->shape.setOutlineColor(sf::Color::Red);
				}
				this->render(window);
				sf::sleep(sf::milliseconds(20));
				this->bricks->bricks[j]->shape.setOutlineColor(sf::Color::Black);
			}
			//Swop values.
			this->swopTwoInt(&array[min_i], &array[i]);
			this->setBricksColorRed(i, min_i);
			//Reset last compared bricks to color black
			this->render(window);
			sf::sleep(sf::milliseconds(300));
			this->setBricksColorBlack(i, min_i);
			this->bricks->bricks[min_i]->setTextInt(array[min_i]);
			this->bricks->bricks[i]->setTextInt(array[i]);
		}
		this->algoFinished = true;
	}
}

void Algorithms::currentSelectedAlgo(std::vector<int>& array, sf::RenderWindow& window)
{
	//this->Bubble_Sort(array, window);

	this->Selection_Sort(array, window);
}

void Algorithms::update(std::vector<int>* array)
{

}

void Algorithms::renderBrickManager(sf::RenderTarget& target)
{
	this->bricks->render(target);
}

void Algorithms::render(sf::RenderWindow& target)
{
	target.clear(sf::Color(150, 150, 150, 255));

	this->renderBrickManager(target);

	target.display();
}
