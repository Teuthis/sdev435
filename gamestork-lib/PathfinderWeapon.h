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
#include <string>

class PathfinderWeapon :
	public InventoryItem
{
public:
	/// Constructs a new PathfinderWeapon object
	/// @param weaponName The name/label of the weapon item
	/// @param weaponValue Monetary value of the weapon item
	/// @param weaponWeight Weight of the weapon item
	/// @param weaponRange Effective range in squares
	/// @param weaponCategory General type of weapon (dagger, mace, etc)
	/// @param weaponDamage Damage determination formula
	PathfinderWeapon(std::string weaponName = "Weapon", 
		unsigned int weaponValue = 25,
		unsigned int weaponWeight = 15,
		int weaponRange = 1,
		std::string weaponCategory = "Simple weapon",
		std::string weaponDamage = "1D4");

	/// Destroys the PathfinderWeapon object
	virtual ~PathfinderWeapon();

	/// Gets the weapon's effective range
	/// @return Effective range in squares as int
	int getRange() const { return range; }

	/// Sets the weapon's effective range
	/// @param newRange The new range in squares
	void setRange(const int newRange);

	/// Gets the weapon's category
	/// @return The category as string
	std::string getCategory() const { return category; }

	/// Sets the weapon's category
	/// @param newCategory The new category string
	void setCategory(const std::string newCategory);

	/// Gets the damage calculation formula
	/// @return The formula s string
	std::string getDamage() const { return damage; }

	/// Sets the damage calculation formula
	/// @param newDamage The new damage string
	void setDamage(const std::string newDamage);

	/// Gets an integer indicating the class type 
	/// (saves typeof checks when iterating through a collection 
	/// of derived types). Should be overriden by subclasses
	/// @return PathfinderWeapon always returns 2
	virtual int getItemType() const { return 2; }

private:
	/// Range/reach in squares
	int range;

	/// Type of weapon (longsword, dagger, etc)
	std::string category;
	
	/// Damage determination (ex: "1D10 + 3")
	std::string damage;
};

