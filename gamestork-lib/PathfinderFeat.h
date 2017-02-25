//-----------------------------------------------------------------------------
/**
File: PathfinderFeat.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Header file for Pathfinder feat data model
*/
//-----------------------------------------------------------------------------

#pragma once

#include <string>
#include "PathfinderEnumerations.h"

class PathfinderFeat
{
public:
	/// Constructs a new PathfinderFeat object
	/// @param featName The name of the feat
	/// @param prerequisiteAbilityType The prereq ability score type
	/// @param prerequisiteAbilityValue The prereq ability score value
	/// @param prerequisiteAttackBonus Minimum attack bonus to take feat
	/// @param prerequisiteProficiency The required proficiencies
	/// @param prerequisiteClass The character classes allowed to take this feat
	/// @param prerequisiteFeat The name of any required feat
	PathfinderFeat(std::string featName = "Pathfinder Feat",
		CHARACTER_ABILITY prerequisiteAbilityType = STRENGTH, 
		int prerequisiteAbilityValue = 0,
		int prerequisiteAttackBonus = -99,
		int prerequisiteProficiency = 0, 
		int prerequisiteClass = FIGHTER | ROGUE | CLERIC | WIZARD, 
		std::string prerequisiteFeat = "");

	/// Destroys the PathfinderFeat object
	~PathfinderFeat();

	/// Returns a string representation of the feat
	/// @return The feat as a string
	std::string toString() const;

	/// Returns the prerequisite ability type
	CHARACTER_ABILITY getAbilityPrerequisite() const;

	/// Determines whether the specified input meets the ability prerequisite
	/// @param abilityScore The value of an ability score
	/// @param abilityType The type of ability score provided
	/// @return true if the prerequisite is met with the provided values,
	///			false otherwise
	bool meetsAbilityPrerequisite(int abilityScore,
		CHARACTER_ABILITY abilityType) const;

	/// Determines whether the provided input meets the attack bonus prerequisite
	/// @param attackBonus The character's attack bonus
	/// @return True if the prerequisite is met, false otherwise
	bool meetsAttackBonusPrerequisite(int attackBonus) const;

	/// Determines whether the provided proficiency value meets the prerequisite
	/// @param proficiencies The character's proficiency flags
	/// @return true if the prerequisite is met, false otherwise
	bool meetsProficiencyPrerequisite(int proficiencies) const;

	/// Determines whether the provided character class meets the prerequisite
	/// @param characterClass The class of the character
	/// @return true if the prerequisite is met, false otherwise
	bool meetsClassPrerequisite(CHARACTER_CLASS characterClass) const;

	/// Gets the prerequisite feat, if any
	/// @return The name of the prerequisite feat or an empty string
	std::string getFeatPrerequisite() const { return featPrereq; }

private:
	/// Feat name
	std::string name;

	/// Ability type for any applicable ability prerequisite
	CHARACTER_ABILITY abilityPrereqType;

	/// Ability score prerequisite minimum
	int abilityPrereqValue;

	/// Base attack bonus prerequisiste minimum
	int attackPrereq;

	/// Weapon/armor proficiency prerequisite(s)
	int proficiencyPrereq;

	/// Character class prerequisite
	int classPrereq;

	/// Prerequisite feat
	std::string featPrereq;
};

