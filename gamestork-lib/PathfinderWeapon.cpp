//-----------------------------------------------------------------------------
/**
File: PathfinderWeapon.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Implementation file for a weapon inventory item for the Pathfinder
rules system. Subclass of InventoryItem.
*/
//-----------------------------------------------------------------------------

#include "PathfinderWeapon.h"


/// Constructs a new PathfinderWeapon object
/// @param weaponName The name/label of the weapon item
/// @param weaponValue Monetary value of the weapon item
/// @param weaponWeight Weight of the weapon item
/// @param weaponRange Effective range in squares
/// @param weaponCategory General type of weapon (dagger, mace, etc)
/// @param weaponDamage Damage determination formula
PathfinderWeapon::PathfinderWeapon(
	std::string weaponName, 
	unsigned int weaponValue, 
	unsigned int weaponWeight, 
	int weaponRange, 
	std::string weaponCategory, 
	std::string weaponDamage)
	: InventoryItem(weaponName, weaponValue, weaponWeight),
	range(weaponRange), category(weaponCategory), damage(weaponDamage)
{
}

/// Destroys the PathfinderWeapon object
PathfinderWeapon::~PathfinderWeapon()
{
}

/// Sets the weapon's effective range
/// @param newRange The new range in squares
void PathfinderWeapon::setRange(const int newRange)
{
	range = newRange;
}

/// Sets the weapon's category
/// @param newCategory The new category string
void PathfinderWeapon::setCategory(const std::string newCategory)
{
	category = newCategory;
}

/// Sets the damage calculation formula
/// @param newDamage The new damage string
void PathfinderWeapon::setDamage(const std::string newDamage)
{
	damage = newDamage;
}
