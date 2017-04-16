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
/// @param armorWeightClass The weight class (light, medium, heavy, shield)
/// @param armorBonus The change to character AC provided
PathfinderArmor::PathfinderArmor(
	std::string armorName,
	unsigned int armorValue,
	ARMOR_WEIGHTCLASS armorWeightClass,
	int armorBonus)
	: InventoryItem(armorName, armorValue),
	weightClass(armorWeightClass), acBonus(armorBonus), specialProperties("")
{
}

/// Destroys the PathfinderArmor object
PathfinderArmor::~PathfinderArmor()
{
}

/// Sets the armor's weight class
/// @param newWeightClass The new weight class
void PathfinderArmor::setWeightClass(const ARMOR_WEIGHTCLASS newWeightClass)
{
	weightClass = newWeightClass;
}

/// Sets the armor's AC bonus
/// @param newACBonus The new modifier value
void PathfinderArmor::setACModifier(const int newACBonus)
{
	acBonus = newACBonus;
}


/// Sets the special properties description for the armor
/// @param newProperties The new special properties description
void PathfinderArmor::setSpecialProperties(const std::string newProperties)
{
	specialProperties = newProperties;
}
