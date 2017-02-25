//-----------------------------------------------------------------------------
/**
File: PathfinderArmor.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Implementation file for an armor inventory item for the Pathfinder
rules system. Subclass of InventoryItem.
*/
//-----------------------------------------------------------------------------

#include "PathfinderArmor.h"

/// Constructs a new PathfinderArmor object
/// @param armorName The name of the armor item
/// @param armorValue The monetary value of the armor
/// @param armorWeight The weight of the armor
/// @param armorWeightClass The weight class (light, medium heavy)
/// @param armorBonus The change to character AC provided
PathfinderArmor::PathfinderArmor(
	std::string armorName,
	unsigned int armorValue,
	unsigned int armorWeight,
	std::string armorWeightClass,
	int armorBonus)
	: InventoryItem(armorName, armorValue, armorWeight),
	weightClass(armorWeightClass), acBonus(armorBonus), checkPenalty(0),
	spellFailure(0), specialProperties("")
{
}

/// Destroys the PathfinderArmor object
PathfinderArmor::~PathfinderArmor()
{
}

/// Sets the armor's weight class
/// @param newWeightClass The new weight class
void PathfinderArmor::setWeightClass(const std::string newWeightClass)
{
	weightClass = newWeightClass;
}

/// Sets the armor's AC bonus
/// @param newACBonus The new modifier value
void PathfinderArmor::setACModifier(const int newACBonus)
{
	acBonus = newACBonus;
}

/// Sets the skill check penalty
/// @param newPenalty The new check penalty value
void PathfinderArmor::setSkillCheckPenalty(const int newPenalty)
{
	checkPenalty = newPenalty;
}

/// Sets the spell failure modifier
/// @param newSpellFailure The new modifier
void PathfinderArmor::setSpellFailure(const int newSpellFailure)
{
	spellFailure = newSpellFailure;
}

/// Sets the special properties description for the armor
/// @param newProperties The new special properties description
void PathfinderArmor::setSpecialProperties(const std::string newProperties)
{
	specialProperties = newProperties;
}
