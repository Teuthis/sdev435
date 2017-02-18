//-----------------------------------------------------------------------------
/**
File: NSidedDie.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Header file for NSidedDie dice simulation
*/
//-----------------------------------------------------------------------------

#pragma once

#include <memory>
#include <random>

/// Enumeration of dice types. Represents the number of faces the die has.
enum DICE {
	D2 = 2,
	D4 = 4,
	D6 = 6,
	D8 = 8,
	D10 = 10,
	D12 = 12,
	D20 = 20,
	D100 = 100
};

/// Represents an individual n-sided die
class NSidedDie
{
public:
	/// Constructs a new NSidedDie
	NSidedDie();

	/// Constructs a new NSidedDie
	/// @param sides The number of faces on the die
	/// @param generator A pointer to a shared linear congruential engine
	NSidedDie(DICE sides, std::shared_ptr<std::minstd_rand> generator);

	/// Copies an existing NSidedDie instance
	/// @param other The NSidedDie instance to copy
	NSidedDie(const NSidedDie &other);
	
	/// Destroys an NSidedDie
	~NSidedDie();

	/// Assigns a copy of the NSidedDie object to a new variable
	/// @param rhs The NSidedDie to assign
	/// @return Reference to the new object
	NSidedDie& operator=(const NSidedDie &rhs);
	
	/// Rolls the die
	/// @return An integer between 1 and N, where N is the number of sides
	int roll();

private:
	
	/// Pointer to a shared linear congruential engine
	std::shared_ptr<std::minstd_rand> generator;

	/// The random integer distribution for this die
	std::uniform_int_distribution<> distribution;
};

