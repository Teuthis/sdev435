//-----------------------------------------------------------------------------
/**
File: PathfinderRogue.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Header file pathfinder rogue class
*/
//-----------------------------------------------------------------------------

#pragma once

#include "PathfinderClass.h"

class PathfinderRogue :
	public PathfinderClass
{
public:
	/// Constructs a new PathfinderRogue object
	PathfinderRogue();

	/// Destroys the PathfinderRogue object
	~PathfinderRogue();

	/// Returns a string representation of the object
	/// @return The object as string
	std::string toString() const { return "Rogue"; }

	/// Returns an integer representation of the object
	/// @return The CHARACTER_CLASS associated with the object
	CHARACTER_CLASS toClassType() const { return ROGUE; }

	/// Returns a collection of strings representing class features
	/// @return The list of features
	std::vector<std::string> getClassFeatures() const;

	/// Gets the information to display in the Spells/Magic section
	/// @return A vector of strings to populate the Magic box
	std::vector<std::string> getMagic() const;

	/// Returns the default starting currency for the class
	/// @return The amount of money a character of this class begins with
	int getStartingMoney() const;
};

