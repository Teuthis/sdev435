//-----------------------------------------------------------------------------
/**
File: PathfinderElf.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Implementation file for Pathfinder elf race data model.
*/
//-----------------------------------------------------------------------------

#include "PathfinderElf.h"



PathfinderElf::PathfinderElf()
	: PathfinderRace()
{
	addTrait("Low-Light Vision");
	addTrait("Elven Immunities");
	addTrait("Keen Senses");
}


PathfinderElf::~PathfinderElf()
{
}

int PathfinderElf::abilityBonus(const CHARACTER_ABILITY ability) const
{
	switch (ability) {
	case DEXTERITY:
	case INTELLIGENCE:
		return 2;
	case CONSTITUTION:
		return -2;
	default:
		return 0;
	}
}

int PathfinderElf::moveSpeedInFeet(const ARMOR_WEIGHTCLASS armorWeight) const
{
	if (armorWeight == HEAVY_WEIGHT || armorWeight == MEDIUM_WEIGHT) {
		return 20;
	} else {
		return 30;
	}
}

int PathfinderElf::moveSpeedInSquares(const ARMOR_WEIGHTCLASS armorWeight) const
{
	if (armorWeight == HEAVY_WEIGHT || armorWeight == MEDIUM_WEIGHT) {
		return 4;
	} else {
		return 6;
	}
}

CREATURE_SIZE PathfinderElf::getSize() const
{
	return SIZE_MEDIUM;
}

int PathfinderElf::getBonusFeats() const
{
	return 0;
}

int PathfinderElf::getBonusSkillRanks() const
{
	return 0;
}
