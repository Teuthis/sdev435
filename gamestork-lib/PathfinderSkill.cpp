//-----------------------------------------------------------------------------
/**
File: PathfinderSkill.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Implementation file for Pathfinder skill data model
*/
//-----------------------------------------------------------------------------

#include "PathfinderSkill.h"

/// Constructs a new PathfinderSkill object
/// @param skillName The name of the skill
/// @param skillAbility The ability score used by the skill
/// @param requiresTraining Indicates if skill can be used at rank 0
PathfinderSkill::PathfinderSkill(
	CHARACTER_SKILLS skillID, std::string skillName, 
	CHARACTER_ABILITY skillAbility, bool requiresTraining)
	: id(skillID), name(skillName), ranks(0), linkedAbility(skillAbility),
	trainedOnly(requiresTraining), classSkill(false), miscModifiers(0)
{
}

/// Destroys the PathfinderSkill object
PathfinderSkill::~PathfinderSkill()
{
}

/// Increases or decreases the number of skill ranks
/// @param amount The number of ranks to increase or decrease. Negative
///				  values decrease.
void PathfinderSkill::addRanks(const int amount)
{
	ranks += amount;
	ranks = ranks < 0 ? 0 : ranks;
}

/// Gets the miscellaneous modifiers
/// @return The miscellaneous modifier total
void PathfinderSkill::toggleClassSkill()
{
	classSkill = !classSkill;
}

/// Increases or decreases the miscellaneous modifiers by the given amount
/// @param amount The amount of increase or decrease
void PathfinderSkill::addModifier(const int amount)
{
	miscModifiers += amount;
}

/// Gets the bonus modifier from ranks
/// @return The modifier amount
int PathfinderSkill::getRankModifier() const
{
	if (classSkill) {
		return ranks * 3;
	} else {
		return ranks;
	}
}

/// Gets the skill as a string
/// @return The skill as a string
std::string PathfinderSkill::toString() const
{
	return name;
}

CHARACTER_SKILLS PathfinderSkill::toSkillID() const
{
	return id;
}
