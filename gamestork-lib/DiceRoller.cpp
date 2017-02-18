//-----------------------------------------------------------------------------
/**
File: DiceRoller.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Implementation file for DiceRoller dice simulator
*/
//-----------------------------------------------------------------------------

#include "DiceRoller.h"

/// Constructs a new DiceRoller object
DiceRoller::DiceRoller()
	: device(),
	generator(std::make_shared<std::minstd_rand>(device())),
	diceBag({
		{ D2, NSidedDie(D2, generator) },
		{ D4, NSidedDie(D4, generator) },
		{ D6, NSidedDie(D6, generator) },
		{ D8, NSidedDie(D8, generator) },
		{ D10, NSidedDie(D10, generator) },
		{ D12, NSidedDie(D12, generator) },
		{ D20, NSidedDie(D20, generator) },
		{ D100, NSidedDie(D100, generator) }
	})
{
}

/// Destroys a DiceRoller object
DiceRoller::~DiceRoller()
{
}

/// Gets the total sum result of rolling one or more dice
/// @param quantity The number of dice to roll
/// @param die The type of dice to roll
/// @return The sum total of the rolls as int
/// @throws std::invalid_argument 
int DiceRoller::getRollSum(int quantity, DICE die)
{
	if (quantity < 1) {
		throw std::invalid_argument("quantity must be greater than 0");
	}
	int sum = 0;
	for (int i = 0; i < quantity; ++i) {
		sum += diceBag[die].roll();
	}
	return sum;
}

/// Gets the individual roll results of rolling one or more dice
/// @param quantity The number of dice to roll
/// @param die The type of dice to roll
/// @return A vector of size quantity containing the roll results
/// @throws std::invalid_argument
std::vector<int> DiceRoller::getRollValues(int quantity, DICE die)
{
	if (quantity < 1) {
		throw std::invalid_argument("quantity must be greater than 0");
	}
	std::vector<int> rolls;
	for (int i = 0; i < quantity; ++i) {
		rolls.push_back(diceBag[die].roll());
	}
	return rolls;
}
