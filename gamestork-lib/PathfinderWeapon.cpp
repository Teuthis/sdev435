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
/// @param weaponRange Effective range in squares
/// @param weaponCategory General type of weapon (melee/ranged)
/// @param weaponDamage Damage determination formula
/// @param weaponDamageType The type of damage (slashing, etc) inflicted
/// @param criticalThreat The critical hit rules for this weapon
PathfinderWeapon::PathfinderWeapon(
	std::string weaponName, 
	unsigned int weaponValue,  
	int weaponRange, 
	WEAPON_CATEGORY weaponCategory, 
	std::string weaponDamage,
	char weaponDamageType,
	std::string criticalThreat)
	: InventoryItem(weaponName, weaponValue),
	range(weaponRange), category(weaponCategory), damage(weaponDamage),
	damageType(weaponDamageType), critical(criticalThreat)
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
void PathfinderWeapon::setCategory(const WEAPON_CATEGORY newCategory)
{
	category = newCategory;
}

/// Sets the damage calculation formula
/// @param newDamage The new damage string
void PathfinderWeapon::setDamage(const std::string newDamage)
{
	damage = newDamage;
}

void PathfinderWeapon::setDamageType(const char typeCode)
{
	if (typeCode == 'S' || typeCode == 'P' || typeCode == 'B'
		|| typeCode == 'M') {
		damageType = typeCode;
	}
}

void PathfinderWeapon::setCriticalThreat(const std::string criticalThreat)
{
	critical = criticalThreat;
}
