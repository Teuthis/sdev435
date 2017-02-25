//-----------------------------------------------------------------------------
/**
File: InventoryItem.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Header file for a simple inventory item for any RPG rules system.
			 Units of weight and value are unspecified, so they may be 
			 determined by the needs of the particular system
*/
//-----------------------------------------------------------------------------

#pragma once

#include <string>

class InventoryItem
{
public:
	/// Default constructor for a new inventory item
	/// @param itemName The name of the item. 
	/// @param itemValue The monetary value of the item
	/// @param itemWeight The weight of the item
	InventoryItem(std::string itemName = "Simple Item", 
		unsigned int itemValue = 1, unsigned int itemWeight = 1);

	/// Destroys the InventoryItem object
	virtual ~InventoryItem();

	/// Gets the name/label of the InventoryItem
	/// @return The name as string
	std::string getName() const { return name; }

	/// Sets the name/label of the InventoryItem
	/// @param newName The new name of the item
	void setName(const std::string newName);

	/// Gets the monetary value of the InventoryItem
	/// @return The value as an unsigned int
	unsigned int getValue() const { return value; }

	/// Sets the monetary value of the InventoryItem
	/// @param newValue The new monetary value of the item
	void setValue(const unsigned int newValue);

	/// Gets the weight of the InventoryItem
	/// @return The weight as an unsigned int
	unsigned int getWeight() const { return weight; }

	/// Sets the weight of the InventoryItem
	/// @param newWeight The new weight of the item
	void setWeight(const unsigned int newWeight);

	/// Gets an integer indicating the class type 
	/// (saves typeof checks when iterating through a collection 
	/// of derived types). Should be overriden by subclasses
	/// @return Base InventoryItem always returns 0
	virtual int getItemType() const { return 0; }

protected:
	/// Item name/label
	std::string name;

	/// Monetary value (in whole amounts of an unspecified unit)
	unsigned int value;

	/// Weight (in whole amounts of an unspecified unit)
	unsigned int weight;	
};

