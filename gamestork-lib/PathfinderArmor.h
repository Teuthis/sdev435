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
#include <string>

class PathfinderArmor :
	public InventoryItem
{
public:
	/// Constructs a new PathfinderArmor object
	/// @param armorName The name of the armor item
	/// @param armorValue The monetary value of the armor
	/// @param armorWeight The weight of the armor
	/// @param armorWeightClass The weight class (light, medium heavy)
	/// @param armorBonus The change to character AC provided
	PathfinderArmor(std::string armorName = "Armor", 
		unsigned int armorValue = 100,
		unsigned int armorWeight = 50, 
		std::string armorWeightClass = "medium",
		int armorBonus = 2);

	/// Destroys the PathfinderArmor object
	virtual ~PathfinderArmor();

	/// Gets the armor's weight class
	/// @return The weight class as string
	std::string getWeightClass() const { return weightClass; }

	/// Sets the armor's weight class
	/// @param newWeightClass The new weight class
	void setWeightClass(const std::string newWeightClass);

	/// Gets the armor's bonus to character AC
	/// @return The AC modifier
	int getACModifier() const { return acBonus; }

	/// Sets the armor's AC bonus
	/// @param newACBonus The new modifier value
	void setACModifier(const int newACBonus);

	/// Gets the skill check penalty incurred by the armor
	/// @return The skill check modifier
	int getSkillCheckPenalty() const { return checkPenalty; }

	/// Sets the skill check penalty
	/// @param newPenalty The new check penalty value
	void setSkillCheckPenalty(const int newPenalty);

	/// Gets the spell failure modifier incurred by wearing the armor
	/// @return The spell failure modifier
	int getSpellFailure() const { return spellFailure; }

	/// Sets the spell failure modifier
	/// @param newSpellFailure The new modifier
	void setSpellFailure(const int newSpellFailure);

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
	
	std::string weightClass;

	int acBonus;

	int checkPenalty;

	int spellFailure;

	std::string specialProperties;
};

