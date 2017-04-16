//-----------------------------------------------------------------------------
/**
File: PathfinderArmor.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Header file for an armor inventory item for the Pathfinder rules 
system. Subclass of InventoryItem.
*/
//-----------------------------------------------------------------------------

#pragma once

#include "InventoryItem.h"
#include "PathfinderEnumerations.h"
#include <string>

class PathfinderArmor :
	public InventoryItem
{
public:
	/// Constructs a new PathfinderArmor object
	/// @param armorName The name of the armor item
	/// @param armorValue The monetary value of the armor
	/// @param armorWeightClass The weight class (light, medium, heavy, shield)
	/// @param armorBonus The change to character AC provided
	PathfinderArmor(std::string armorName = "Armor", 
		unsigned int armorValue = 100,
		ARMOR_WEIGHTCLASS armorWeightClass = MEDIUM_WEIGHT,
		int armorBonus = 2);

	/// Destroys the PathfinderArmor object
	virtual ~PathfinderArmor();

	/// Gets the armor's weight class
	/// @return The weight class from ARMOR_WEIGHTCLASS enumeration
	ARMOR_WEIGHTCLASS getWeightClass() const { return weightClass; }

	/// Sets the armor's weight class
	/// @param newWeightClass The new weight class
	void setWeightClass(const ARMOR_WEIGHTCLASS newWeightClass);

	/// Gets the armor's bonus to character AC
	/// @return The AC modifier
	int getACModifier() const { return acBonus; }

	/// Sets the armor's AC bonus
	/// @param newACBonus The new modifier value
	void setACModifier(const int newACBonus);

	/// Gets the description of special armor properties
	/// @return A string describing the armor's special properties
	std::string getSpecialProperties() const { return specialProperties; }

	/// Sets the special properties description for the armor
	/// @param newProperties The new special properties description
	void setSpecialProperties(const std::string newProperties);

	/// Gets an integer indicating the class type 
	/// (saves typeof checks when iterating through a collection 
	/// of derived types). Should be overriden by subclasses
	/// @return PathfinderArmor always returns 1
	virtual int getItemType() const { return 1; }

private:
	/// The weight class of this armor item
	ARMOR_WEIGHTCLASS weightClass;

	/// The amount of armor contributed
	int acBonus;

	/// Any special magical properties
	std::string specialProperties;
};

