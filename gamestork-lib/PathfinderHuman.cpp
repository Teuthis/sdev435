//-----------------------------------------------------------------------------
/**
File: PathfinderHuman.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Implementation file for Pathfinder human race data model.
*/
//-----------------------------------------------------------------------------

#include "PathfinderHuman.h"

PathfinderHuman::PathfinderHuman(CHARACTER_ABILITY bonusAbility)
	: PathfinderRace(), bonus(bonusAbility)
{
	addTrait("Skilled");
	addTrait("Bonus Feat");
	addTrait("Languages");
}

PathfinderHuman::~PathfinderHuman()
{
}

int PathfinderHuman::abilityBonus(const CHARACTER_ABILITY ability) const
{
	if (ability == bonus) {
		return 2;
	} else {
		return 0;
	}
}

int PathfinderHuman::moveSpeedInFeet(const ARMOR_WEIGHTCLASS armorWeight) const
{
	if (armorWeight == HEAVY_WEIGHT || armorWeight == MEDIUM_WEIGHT) {
		return 20;
	} else {
		return 30;
	}
}

int PathfinderHuman::moveSpeedInSquares(const ARMOR_WEIGHTCLASS armorWeight) const
{
	if (armorWeight == HEAVY_WEIGHT || armorWeight == MEDIUM_WEIGHT) {
		return 4;
	} else {
		return 6;
	}
}

CREATURE_SIZE PathfinderHuman::getSize() const
{
	return SIZE_MEDIUM;
}

int PathfinderHuman::getBonusFeats() const
{
	return 1;
}

int PathfinderHuman::getBonusSkillRanks() const
{
	return 1;
}

