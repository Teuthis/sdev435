//-----------------------------------------------------------------------------
/**
	File: DiceRoller.h
	System: Gamestork RPG Character Generator
	License: LGPL
	(c) Chris Aiken, Jason Roberge 2017

	Description: Header file for DiceRoller dice simulator
*/
//-----------------------------------------------------------------------------

#pragma once

#include "NSidedDie.h"
#include <memory>
#include <random>
#include <map>
#include <vector>
#include <stdexcept>

/// Simulates an RPG dice collection
class DiceRoller
{
public:
	/// Constructs a new DiceRoller object
	DiceRoller();

	/// Destroys a DiceRoller object
	~DiceRoller();

	/// Gets the total sum result of rolling one or more dice
	/// @param quantity The number of dice to roll
	/// @param die The type of dice to roll
	/// @return The sum total of the rolls as int
	/// @throws std::invalid_argument 
	int getRollSum(int quantity, DICE die);

	/// Gets the individual roll results of rolling one or more dice
	/// @param quantity The number of dice to roll
	/// @param die The type of dice to roll
	/// @return A vector of size quantity containing the roll results
	/// @throws std::invalid_argument
	std::vector<int> getRollValues(int quantity, DICE die);

private:
	std::random_device device;

	/// Pointer to a shared linear congruential engine
	std::shared_ptr<std::minstd_rand> generator;

	/// Dictionary of dice types
	std::map<const DICE, NSidedDie> diceBag;
};

