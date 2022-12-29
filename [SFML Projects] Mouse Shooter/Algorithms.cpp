#include "Algorithms.h"

void Algorithms::initVariables(int pauseTime, int selectedAlgorithm)
{
	this->algoFinished = false;
	this->goBack = false;
}

std::unique_ptr<BrickManager> Algorithms::initBrickManager(sf::Vector2u& winSize, std::vector<int>& array, sf::Font& font, bool UsefullScreen)
{
	return std::make_unique<BrickManager>(winSize, array, font, UsefullScreen);
}

Algorithms::Algorithms(sf::Vector2u& winSize, std::vector<int>& array, sf::Font& font, bool UsefullScreen, int pauseTime, int selectedAlgorithm)
{
	this->initVariables(pauseTime, selectedAlgorithm);
	this->bricks = this->initBrickManager(winSize, array, font, UsefullScreen);
}

Algorithms::~Algorithms()
{
	//delete this->bricks;
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

void Algorithms::resetAlgoFinished()
{
	this->algoFinished = false;
}

const bool& Algorithms::getAlgoFinished() const
{
	return this->algoFinished;
}

void Algorithms::Bubble_Sort(std::vector<int>& array, sf::RenderWindow& window)
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
					sf::sleep(sf::milliseconds(PAUSE_TIMER));
					this->update(window);
				}
				//Reset last compared bricks to color black
				this->setBricksColorBlack(i, j);
				if (this->goBack) return;
			}
		}
}

void Algorithms::Selection_Sort(std::vector<int>& array, sf::RenderWindow& window)
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
				sf::sleep(sf::milliseconds(PAUSE_TIMER));
				this->bricks->bricks[j]->shape.setOutlineColor(sf::Color::Black);
				this->update(window);
			}
			//Swop values.
			this->swopTwoInt(&array[min_i], &array[i]);
			this->setBricksColorRed(i, min_i);
			//Reset last compared bricks to color black
			this->render(window);
			sf::sleep(sf::milliseconds(PAUSE_TIMER));
			this->setBricksColorBlack(i, min_i);
			this->bricks->bricks[min_i]->setTextInt(array[min_i]);
			this->bricks->bricks[i]->setTextInt(array[i]);
			if (this->goBack) return;
		}
}

void Algorithms::Insertion_Sort(std::vector<int>& array, sf::RenderWindow& window)
{
	for (int step = 1; step < array.size(); step++)
	{
		int key = array[step];
		int j = step - 1;

		while (j >= 0 && key < array[j])
		{
			array[j + 1] = array[j];
			this->setBricksColorRed(j + 1, j);
			this->renderWithBreak(window, PAUSE_TIMER);
			this->bricks->bricks[j + 1]->setTextInt(array[j + 1]);
			this->renderWithBreak(window, PAUSE_TIMER);
			this->setBricksColorBlack(j + 1, j);
			--j;
			this->update(window);
		}
		array[j + 1] = key;
		this->bricks->bricks[j + 1]->setTextInt(array[j + 1]);
		this->renderWithBreak(window, PAUSE_TIMER);
		if (this->goBack) return;
	}
}

void Algorithms::merge(sf::RenderWindow& window, std::vector<int>& array, int left_index, int mid_index, int right_index)
{
	//Creating indexes
	int i, j, k;

	//Calculating size of the arrays
	int left_size = mid_index - left_index + 1;
	int right_size = right_index - mid_index;

	//Creating subvectors
	std::vector<int> left_vector, right_vector;

	//Fill left vector
	for (i = 0; i < left_size; i++)
	{
		left_vector.push_back(array[static_cast<std::vector<int, std::allocator<int>>::size_type>(left_index) + i]);
		this->bricks->bricks[left_index + i]->shape.setOutlineColor(sf::Color::Green);
	}
	//Fill right vector
	for (j = 0; j < right_size; j++)
	{
		right_vector.push_back(array[static_cast<std::vector<int, std::allocator<int>>::size_type>(mid_index) + 1 + j]);
		this->bricks->bricks[mid_index + 1 + j]->shape.setOutlineColor(sf::Color::Blue);
	}

	//Reset indexes
	i = 0, j = 0, k = left_index;

	//Filling until one side is empty
	while (i < left_size && j < right_size)
	{
		if (left_vector[i] <= right_vector[j])
		{
			this->setBricksColorRed(i, k);
			this->renderWithBreak(window, PAUSE_TIMER);
			array[k] = left_vector[i];
			this->bricks->bricks[k]->setTextInt(array[k]);
			this->renderWithBreak(window, PAUSE_TIMER);
			this->setBricksColorBlack(i, k);
			i++;
		}
		else
		{
			this->setBricksColorRed(k, j);
			this->renderWithBreak(window, PAUSE_TIMER);
			array[k] = right_vector[j];
			this->bricks->bricks[k]->setTextInt(array[k]);
			this->renderWithBreak(window, PAUSE_TIMER);
			this->setBricksColorBlack(k, j);
			j++;
		}
		k++;
	}

	//Filling the left leftovers
	while (i < left_size)
	{
		this->setBricksColorRed(i, k);
		this->renderWithBreak(window, PAUSE_TIMER);
		array[k] = left_vector[i];
		this->bricks->bricks[k]->setTextInt(array[k]);
		this->renderWithBreak(window, PAUSE_TIMER);
		this->setBricksColorBlack(i, k);
		i++;
		k++;
	}

	//Filling the right leftovers
	while (j < right_size)
	{
		this->setBricksColorRed(j, k);
		this->renderWithBreak(window, PAUSE_TIMER);
		array[k] = right_vector[j];
		this->bricks->bricks[k]->setTextInt(array[k]);
		this->renderWithBreak(window, PAUSE_TIMER);
		this->setBricksColorBlack(j, k);
		j++;
		k++;
	}
}

void Algorithms::Merge_Sort(sf::RenderWindow& window, std::vector<int>& array, int left_index, int right_index)
{
	int mid_index;

	//Divide
	if (left_index < right_index)
	{
		mid_index = left_index + (right_index - left_index) / 2;
		if (this->goBack) return;
		Merge_Sort(window, array, left_index, mid_index);
		Merge_Sort(window, array, mid_index + 1, right_index);

		merge(window, array, left_index, mid_index, right_index);
	}
}


void Algorithms::currentSelectedAlgo(std::vector<int>& array, sf::RenderWindow& window, int& indexOfAlgorithm)
{
	if (!this->algoFinished)
	{
		int i = 0;
		if(indexOfAlgorithm == 0)
		this->Bubble_Sort(array, window);
		else if(indexOfAlgorithm == 1)
		this->Selection_Sort(array, window);
		else if (indexOfAlgorithm == 2)
		this->Insertion_Sort(array, window);
		else if (indexOfAlgorithm == 3)
		this->Merge_Sort(window, array, 0 , static_cast<int>(array.size()) - 1);

		this->algoFinished = true;
	}
	//Create button to reset algo finished
}

void Algorithms::pollEvents(sf::RenderWindow& window)
{
	sf::Event ev;
	while (window.pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			this->goBack = true;
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
				this->goBack = true;
			break;
		}
	}
}

void Algorithms::update(sf::RenderWindow& window)
{
	this->pollEvents(window);
	mouse.update(window, false);
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

void Algorithms::renderWithBreak(sf::RenderWindow& target, unsigned int milliseconds)
{
	this->render(target);
	//sf::sleep(sf::milliseconds(milliseconds));
}
