//-----------------------------------------------------------------------------
/**
File: PathfinderDwarf.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Implementation file for Pathfinder dwarf race data model.
*/
//-----------------------------------------------------------------------------

#include "PathfinderDwarf.h"

PathfinderDwarf::PathfinderDwarf()
	: PathfinderRace()
{
	addTrait("Darkvision 60 Feet");
	addTrait("Hatred (+1 vs. Goblins and Orcs)");
	addTrait("Hardy (+2 vs. Poison and Spells)");
}


PathfinderDwarf::~PathfinderDwarf()
{
}

int PathfinderDwarf::abilityBonus(const CHARACTER_ABILITY ability) const
{
	switch (ability) {
	case CONSTITUTION:
	case WISDOM:
		return 2;
	case CHARISMA:
		return -2;
	default:
		return 0;
	}
}

#pragma warning (disable : 4100) /* Disable unreferenced param warning
									armorWeight not used for dwarves, but virtual
									function signature requires it. */
int PathfinderDwarf::moveSpeedInFeet(const ARMOR_WEIGHTCLASS armorWeight) const
{
	return 20;
}

int PathfinderDwarf::moveSpeedInSquares(const ARMOR_WEIGHTCLASS armorWeight) const
{
	return 4;
}
#pragma warning (default : 4100) /* Revert to normal */

CREATURE_SIZE PathfinderDwarf::getSize() const
{
	return SIZE_MEDIUM;
}
