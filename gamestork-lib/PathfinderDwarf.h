//-----------------------------------------------------------------------------
/**
File: PathfinderDwarf.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Header file for Pathfinder dwarf race data model.
*/
//-----------------------------------------------------------------------------

#pragma once

#include "PathfinderRace.h"

class PathfinderDwarf :
	public PathfinderRace
{
public:
	/// Constructs a new PathfinderDwarf object
	PathfinderDwarf();

	/// Destroys the PathfinderDwarf object
	~PathfinderDwarf();

	/// Returns a string representation
	/// @return Always returns "Dwarf"
	std::string toString() const { return "Dwarf"; }

	/// Returns the bonus for the given ability
	/// @param ability The requested ability score 
	/// @return An integer representing the bonus for the requested ability
	int abilityBonus(const CHARACTER_ABILITY ability) const;

	/// Returns the base movement speed in feet
	/// @param armorWeight The weight class of the currently equipped armor
	/// @return Movement speed in feet
	int moveSpeedInFeet(const ARMOR_WEIGHTCLASS armorWeight) const;

	/// Returns the base movement speed in squares
	/// @param armorWeight The weight class of the currently equipped armor
	/// @return Movement speed in squares
	int moveSpeedInSquares(const ARMOR_WEIGHTCLASS armorWeight) const;

	/// Returns this character race's size
	/// @return The size as CREATURE_SIZE
	CREATURE_SIZE getSize() const;
};

