#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "PathfinderEnumerations.h"
#include "PathfinderHuman.h"
#include "PathfinderDwarf.h"
#include "PathfinderElf.h"
#include "PathfinderFighter.h"
#include "PathfinderCleric.h"
#include "PathfinderRogue.h"
#include "PathfinderWizard.h"
#include "PathfinderFeat.h"
#include "PathfinderArmor.h"
#include "PathfinderWeapon.h"
#include "InventoryItem.h"

class PathfinderCharacter
{
public:
	// Parameterless ctor prohibited
	PathfinderCharacter() = delete;

	/// Constructs a new PathfinderCharacter object
	/// @param characterClass The class of the character being created
	PathfinderCharacter(CHARACTER_CLASS chosenClass);

	/// Destroys the PathfinderCharacter object
	~PathfinderCharacter();

	/// Gets the number of gold pieces the character possesses
	/// @return The number of gold pieces (1 gp == 10 sp == 100 cp)
	int getGoldPieces() const;

	/// Gets the number of silver pieces the character possesses
	/// @return The number of silver pieces (1 sp == 10 cp, 10 sp == 1 gp)
	int getSilverPieces() const;

	/// Gets the number of copper pieces the character possesses
	/// @return The number of copper pieces (10 cp == 1 sp, 100 cp == 1 gp)
	int getCopperPieces() const;

	/// Attempts to add an item to the character's inventory, provided the 
	/// character has enough money to purchase the item
	/// @param item The item to add to inventory
	/// @return true if the item was successfully purchased, 
	///			false if insufficient funds
	bool buyItem(const InventoryItem item);

	/// Gets the character's name
	/// @return The character's name
	std::string getName() const;

	/// Sets the character's name
	/// @param newName The new name value to set
	void setName(const std::string newName);

	/// Gets the character's philosophical alignment
	/// @return The alignment value
	ALIGNMENT getAlignment() const;

	/// Sets the character's philosophical alignment
	/// @param newAlign The new alignment value
	void setAlignment(ALIGNMENT newAlign);

	/// Gets the character's race/species
	/// @return The race as string
	std::string getRace() const;

	/// Sets the character's race/species
	/// @param newRace The new race value
	void setRace(CHARACTER_RACE newRace);

private:
	std::string name;

	//TODO gender

	ALIGNMENT alignment;

	std::unique_ptr<PathfinderRace> race;

	std::unique_ptr<PathfinderClass> charClass;

	std::map<CHARACTER_ABILITY, int> abilityScores;

	std::vector<PathfinderFeat> feats;

	std::vector<InventoryItem> inventory;

	int money;
};
