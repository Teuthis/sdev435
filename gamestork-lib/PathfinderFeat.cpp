//-----------------------------------------------------------------------------
/**
File: PathfinderFeat.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Implementation file for Pathfinder feat data model
*/
//-----------------------------------------------------------------------------

#include "PathfinderFeat.h"

/// Constructs a new PathfinderFeat object
/// @param featName The name of the feat
/// @param prerequisiteAbilityType The prereq ability score type
/// @param prerequisiteAbilityValue The prereq ability score value
/// @param prerequisiteAttackBonus Minimum attack bonus to take feat
/// @param prerequisiteProficiency The required proficiencies
/// @param prerequisiteClass The character classes allowed to take this feat
/// @param prerequisiteFeat The name of any required feat
PathfinderFeat::PathfinderFeat(std::string featName, 
	CHARACTER_ABILITY prerequisiteAbilityType, 
	int prerequisiteAbilityValue, 
	int prerequisiteAttackBonus,
	int prerequisiteProficiency, 
	int prerequisiteClass)
	: name(featName), abilityPrereqType(prerequisiteAbilityType),
	abilityPrereqValue(prerequisiteAbilityValue), 
	attackPrereq(prerequisiteAttackBonus),
	proficiencyPrereq(prerequisiteProficiency), 
	classPrereq(prerequisiteClass)
{
}

/// Destroys the PathfinderFeat object
PathfinderFeat::~PathfinderFeat()
{
}

/// Returns a string representation of the feat
/// @return The feat as a string
std::string PathfinderFeat::toString() const
{
	return name;
}

/// Returns the prerequisite ability type
CHARACTER_ABILITY PathfinderFeat::getAbilityPrerequisite() const
{
	return abilityPrereqType;
}

/// Determines whether the specified input meets the ability prerequisite
/// @param abilityScore The value of an ability score
/// @param abilityType The type of ability score provided
/// @return true if the prerequisite is met with the provided values,
///			false otherwise
bool PathfinderFeat::meetsAbilityPrerequisite(int abilityScore, 
	CHARACTER_ABILITY abilityType) const
{
	return abilityPrereqType == abilityType
		&& abilityScore >= abilityPrereqValue;
}

/// Determines whether the provided input meets the attack bonus prerequisite
/// @param attackBonus The character's attack bonus
/// @return True if the prerequisite is met, false otherwise
bool PathfinderFeat::meetsAttackBonusPrerequisite(int attackBonus) const
{
	return attackBonus >= attackPrereq;
}

/// Determines whether the provided proficiency value meets the prerequisite
/// @param proficiencies The character's proficiency flags
/// @return true if the prerequisite is met, false otherwise
bool PathfinderFeat::meetsProficiencyPrerequisite(int proficiencies) const
{
	if (proficiencyPrereq == 0) {
		return true;
	} else {
		return (proficiencies & proficiencyPrereq) > 0;
	}
}

/// Determines whether the provided character class meets the prerequisite
/// @param characterClass The class of the character
/// @return true if the prerequisite is met, false otherwise
bool PathfinderFeat::meetsClassPrerequisite(CHARACTER_CLASS characterClass) const
{
	int bitmask = characterClass & classPrereq;
	return bitmask != 0;
}
