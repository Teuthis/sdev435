//-----------------------------------------------------------------------------
/**
File: PathfinderRace.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Header file for Pathfinder character race data model abstract 
			base class.
*/
//-----------------------------------------------------------------------------

#pragma once
#include <string>
#include <vector>
#include <map>
#include "PathfinderEnumerations.h"

class PathfinderRace
{
public:
	/// Destroys the PathfinderRace object
	virtual ~PathfinderRace() {}
	
	/// Returns a string representation of the PathfinderRace object
	/// @return The race as a string
	virtual std::string toString() const = 0;

	/// Returns an integer identifier of the PathfinderRace object
	/// @return The CHARACTER_RACE enum value of the race
	virtual CHARACTER_RACE toInt() const = 0;

	/// Returns the bonus for the given ability
	/// @param ability The requested ability score 
	/// @return An integer representing the bonus for the requested ability
	virtual int abilityBonus(const CHARACTER_ABILITY ability) const = 0;

	/// Returns the base movement speed in feet
	/// @param armorWeight The weight class of the currently equipped armor
	/// @return Movement speed in feet
	virtual int moveSpeedInFeet(const ARMOR_WEIGHTCLASS armorWeight) const = 0;

	/// Returns the base movement speed in squares
	/// @param armorWeight The weight class of the currently equipped armor
	/// @return Movement speed in squares
	virtual int moveSpeedInSquares(const ARMOR_WEIGHTCLASS armorWeight) const = 0;

	/// Returns this character race's size
	/// @return The size as CREATURE_SIZE
	virtual CREATURE_SIZE getSize() const = 0;

	/// Returns the list of racial traits
	/// @return A vector of trait strings
	std::vector<std::string> getTraits() {
		return traits;
	}

	/// Returns the number of bonus feats for this race
	/// @return The number of additional feats at level 1
	virtual int getBonusFeats() const = 0;

	/// Returns the number of bonus skill ranks for this race
	/// @return The number of additional skill ranks at level 1
	virtual int getBonusSkillRanks() const = 0;

protected:
	/// Constructs a new PathfinderRace object
	PathfinderRace() : traits() {}

	/// Adds a trait to the list
	/// Derived classes should do this in their constructors, as race classes
	/// are intended to be immutable
	/// @param trait The trait to add
	void addTrait(std::string trait) {
		traits.push_back(trait);
	}

private:
	/// List of racial traits
	std::vector<std::string> traits;
	
};

