#pragma once

#include<iostream>
#include<time.h>
#include<vector>

class Generation
{
private:

	void initVariables();
	void initVectorArray(int sizeOfArray, int NumberCap, bool randomizeNumbers, bool doubleNumbers);
public:
	/// <summary>
	/// Generates a public vector array with randomized or sorted numbers.
	/// Number Cap sets the highest possibly generated number.
	/// doubleNumbers set on true allow the same numbers multiple times.
	/// </summary>
	/// <param name="sizeOfArray"></param>
	/// <param name="NumberCap"></param>
	/// <param name="randomizeNumbers"></param>
	Generation(int sizeOfArray, int NumberCap, bool randomizeNumbers, bool doubleNumbers);
	virtual ~Generation();

	void shuffleArray();

	std::vector<int> array;

	void printArrayInConsole();
};

