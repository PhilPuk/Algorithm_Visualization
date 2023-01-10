#include "Generation.h"

void Generation::initVariables()
{

}

void Generation::initVectorArray(int sizeOfArray, int NumberCap, bool randomizeNumbers, bool doubleNumbers)
{
	if (randomizeNumbers)
	{
		//Create randomized array
			for (int i = 0; i < sizeOfArray; i++)
			{
				array.push_back(rand() % NumberCap);
			}
			//Removes doubled numbers
			if (!doubleNumbers)
			{
					for (int i = 0; i < sizeOfArray; i++)
					{
						for (int j = i + 1; j < sizeOfArray; j++)
						{
							if (array[i] == array[j])
							{
								this->array[j] = rand() % NumberCap;
								i = 0;
								//mistake = true;
							}
						}
					}
			}
	}
	else
	{
		//Created sorted array
		for (int i = 0; i < sizeOfArray; i++)
		{
			array.push_back(i);
		}
	}
}

Generation::Generation(int sizeOfArray, int NumberCap, bool randomizeNumbers, bool doubleNumbers)
{
	this->initVariables();
	this->initVectorArray(sizeOfArray, NumberCap, randomizeNumbers, doubleNumbers);
}

Generation::~Generation()
{

}


void Generation::shuffleArray()
{
	//Create randomized array
	for (int i = 0; i < this->sizeOfArray; i++)
	{
		array.push_back(rand() % this->NumberCap);
	}
	//Removes doubled numbers
	if (!doubleNumbers)
	{
		for (int i = 0; i < this->sizeOfArray; i++)
		{
			for (int j = i + 1; j < this->sizeOfArray; j++)
			{
				if (array[i] == array[j])
				{
					this->array[j] = rand() % this->NumberCap;
					i = 0;
					//mistake = true;
				}
			}
		}
	}
}


void Generation::printArrayInConsole()
{
	std::cout << "\n\nArray:\n";
	for (auto& i : this->array)
	{
		std::cout << i << "\n";
	}
}

