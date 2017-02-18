//-----------------------------------------------------------------------------
/**
File: NSidedDie.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Implementation file for NSidedDie dice simulation
*/
//-----------------------------------------------------------------------------

#include "NSidedDie.h"

/// Constructs a new NSidedDie
NSidedDie::NSidedDie() 
	: generator(), distribution(1, D6)
{
}

/// Constructs a new NSidedDie
/// @param sides The number of faces on the die
/// @param generator A pointer to a shared linear congruential engine
NSidedDie::NSidedDie(DICE sides, std::shared_ptr<std::minstd_rand> generator)
	: generator(generator), distribution(1, sides)
{
}

/// Copies an existing NSidedDie instance
/// @param other The NSidedDie instance to copy
NSidedDie::NSidedDie(const NSidedDie & other)
	: generator(other.generator), distribution(other.distribution)
{
}

/// Destroys an NSidedDie
NSidedDie::~NSidedDie()
{
}

/// Assigns a copy of the NSidedDie object to a new variable
/// @param rhs The NSidedDie to assign
/// @return Reference to the new object
NSidedDie & NSidedDie::operator=(const NSidedDie & rhs)
{
	generator = rhs.generator;
	distribution = rhs.distribution;
	return *this;
}

/// Rolls the die
/// @return An integer between 1 and N, where N is the number of sides
int NSidedDie::roll()
{
	return distribution(*generator);
}
