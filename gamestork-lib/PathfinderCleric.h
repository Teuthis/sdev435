//-----------------------------------------------------------------------------
/**
File: PathfinderCleric.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Header file for Pathfinder cleric class
*/
//-----------------------------------------------------------------------------

#pragma once

#include "PathfinderClass.h"

class PathfinderCleric :
	public PathfinderClass
{
public:
	PathfinderCleric(const std::string deity = "Desna");
	~PathfinderCleric();

	/// Returns a string representation of the object
	/// @return The object as string
	std::string toString() const { return "Cleric"; }

	/// Returns an integer representation of the object
	/// @return The CHARACTER_CLASS associated with the object
	CHARACTER_CLASS toClassType() const { return CLERIC; }

	/// Returns a collection of strings representing class features
	/// @return The list of features
	std::vector<std::string> getClassFeatures() const;

	/// Gets the information to display in the Spells/Magic section
	/// @return A vector of strings to populate the Magic box
	std::vector<std::string> getMagic() const;

	/// Returns the default starting currency for the class
	/// @return The amount of money a character of this class begins with
	int getStartingMoney() const;

	/// Sets the cleric's patron god
	/// @param godName The name of the cleric's patron
	void setPatron(const std::string godName);

	/// Gets the cleric's patron god
	/// @return The name of the patron god
	std::string getPatron() const;

private:
	/// The character's patron god
	std::string chosenDeity;
};

