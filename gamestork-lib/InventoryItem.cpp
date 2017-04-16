//-----------------------------------------------------------------------------
/**
File: InventoryItem.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Implementation file for a simple inventory item for any RPG rules
system. Units of weight and value are unspecified, so they may be
determined by the needs of the particular system
*/
//-----------------------------------------------------------------------------

#include "InventoryItem.h"


/// Default constructor for a new inventory item
/// @param itemName The name of the item. 
/// @param itemValue The monetary value of the item
/// @param itemWeight The weight of the item
InventoryItem::InventoryItem(std::string itemName, 
	unsigned int itemValue) 
	: name(itemName), value(itemValue)
{
}

/// Destroys the InventoryItem object
InventoryItem::~InventoryItem()
{
}

/// Sets the name/label of the InventoryItem
/// @param newName The new name of the item
void InventoryItem::setName(const std::string newName)
{
	name = newName;
}

/// Sets the monetary value of the InventoryItem
/// @param newValue The new monetary value of the item
void InventoryItem::setValue(const unsigned int newValue)
{
	value = newValue;
}
