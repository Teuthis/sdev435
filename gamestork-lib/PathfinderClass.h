//-----------------------------------------------------------------------------
/**
File: PathfinderClass.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Header file for Pathfinder character class abstract base class
			Overlapping terminology. Character class == occupation
*/
//-----------------------------------------------------------------------------

#pragma once

#include <string>
#include <vector>
#include "PathfinderSkill.h"
#include "NSidedDie.h"

class PathfinderClass
{
public:
	/// Destroys the PathfinderClass object
	virtual ~PathfinderClass() {}

	/// Returns a string representation of the object
	/// @return The object as string
	virtual std::string toString() const = 0;

	/// Returns the number of unspent skill ranks
	/// @param intelligence The character's intelligence ability modifier
	/// @return The number of skill ranks remaining to be used
	int getUnspentSkillRanks(const int intelligenceModifier) const;

	/// Returns the base hit points for characters of this class
	/// @return The number of hit points without any modifiers
	int getBaseHitPoints() const;

	/// Returns the Fortitude Save bonus for characters of this class
	/// @return The Fortitude Save modifier
	int getFortitudeBonus() const;

	/// Returns the Reflex Save for characters of this class
	/// @return The Reflex Save modifier
	int getReflexBonus() const;

	/// Returns the Will Save for characters of this class
	/// @return The Will Save modifier
	int getWillBonus() const;

	/// Returns the Attack Bonus for characters of this class
	/// @return The Attack modifier
	int getAttackBonus() const;

	/// Returns a collection of strings representing class features
	/// @return The list of features
	virtual std::vector<std::string> getClassFeatures() const = 0;

	/// Attempts to add a rank to a skill
	/// @param skill The skill to rank up
	/// @return true if the increase was successful, false otherwise
	bool addSkillRank(const CHARACTER_SKILLS skill);

	/// Attempts to remove a rank from a skill
	/// @param skill The skill to rank down
	/// @return true if the removal was successful, false otherwise
	bool removeSkillRank(const CHARACTER_SKILLS skill);

	/// Gets a read-only copy of the skill list
	/// @return The skill list as a const vector
	const std::vector<PathfinderSkill> getSkills() const;

	/// Gets the information to display in the Spells/Magic section
	/// @return A vector of strings to populate the Magic box
	virtual std::vector<std::string> getMagic() const = 0;

	/// Returns the default starting currency for the class
	/// @return The amount of money a character of this class begins with
	virtual int getStartingMoney() const = 0;

protected:
	/// Constructs a new PathfinderClass object
	PathfinderClass(const int fortitude = 0, const int reflex = 0, 
		const int will = 0, const int attack = 0, const int hitpoints = 0, 
		const int baseRanks = 0, const int proficiencies = 0);
	
	/// List of skills
	std::vector<PathfinderSkill> skills;

private:
	/// Class modifier to Fortitude Save
	int fortitudeMod;

	/// Class modifier to Reflex Save
	int reflexMod;

	/// Class modifier to Will Save
	int willMod;

	/// Class modifier to Attack Bonus
	int attackBonus;

	/// Base hitpoints
	int hp;

	/// Base # of skill ranks provided by class
	int baseSkillRanks;

	/// Standard weapon proficiencies
	int weaponArmorProficiencies;

};

