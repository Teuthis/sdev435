//-----------------------------------------------------------------------------
/**
File: PathfinderWeapon.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Header file for a weapon inventory item for the Pathfinder rules
system. Subclass of InventoryItem.
*/
//-----------------------------------------------------------------------------

#pragma once

#include "InventoryItem.h"
#include "PathfinderEnumerations.h"
#include <string>

class PathfinderWeapon :
	public InventoryItem
{
public:
	/// Constructs a new PathfinderWeapon object
	/// @param weaponName The name/label of the weapon item
	/// @param weaponValue Monetary value of the weapon item
	/// @param weaponRange Effective range in squares
	/// @param weaponCategory General type of weapon (melee/ranged)
	/// @param weaponDamage Damage determination formula
	/// @param weaponDamageType The type of damage (slashing, etc) inflicted
	/// @param criticalThreat The critical hit rules for this weapon
	PathfinderWeapon(std::string weaponName = "Weapon", 
		unsigned int weaponValue = 25,
		int weaponRange = 1,
		WEAPON_CATEGORY weaponCategory = MELEE,
		std::string weaponDamage = "1D4",
		char weaponDamageType = 'S',
		std::string criticalThreat = "20");

	/// Destroys the PathfinderWeapon object
	virtual ~PathfinderWeapon();

	/// Gets the weapon's effective range
	/// @return Effective range in squares as int
	int getRange() const { return range; }

	/// Sets the weapon's effective range
	/// @param newRange The new range in squares
	void setRange(const int newRange);

	/// Gets the weapon's category
	/// @return The category as an enumeration
	WEAPON_CATEGORY getCategory() const { return category; }

	/// Sets the weapon's category
	/// @param newCategory The new category
	void setCategory(const WEAPON_CATEGORY newCategory);

	/// Gets the damage calculation formula
	/// @return The formula as string
	std::string getDamage() const { return damage; }

	/// Sets the damage calculation formula
	/// @param newDamage The new damage string
	void setDamage(const std::string newDamage);

	/// Gets the damage type
	/// @return The letter code for the damage type
	char getDamageType() const { return damageType; }

	/// Sets the damage type
	/// @param typeCode The single letter code for the damage type
	void setDamageType(const char typeCode);

	/// Gets the critical threat value
	/// @return A string describing the roll and multiplier for a critical hit
	std::string getCriticalThreat() const { return critical; }

	/// Sets the critical threat value
	/// @param criticalThreat String describing critical roll/multiplier
	void setCriticalThreat(const std::string criticalThreat);

	/// Gets an integer indicating the class type 
	/// (saves typeof checks when iterating through a collection 
	/// of derived types). Should be overriden by subclasses
	/// @return PathfinderWeapon always returns 2
	virtual int getItemType() const { return 2; }

private:
	/// Range/reach in squares
	int range;

	/// Type of weapon (melee, ranged)
	WEAPON_CATEGORY category;
	
	/// Damage determination (ex: "1D10 + 3")
	std::string damage;

	/// Damage type (slashing, piercing, etc)
	char damageType;

	/// Critical damage roll and bonus
	std::string critical;
};

