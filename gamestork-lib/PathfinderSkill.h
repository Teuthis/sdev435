//-----------------------------------------------------------------------------
/**
File: PathfinderSkill.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Header file for Pathfinder skill data model
*/
//-----------------------------------------------------------------------------

#pragma once

#include <string>
#include "PathfinderEnumerations.h"

class PathfinderSkill
{
public:
	/// Constructs a new PathfinderSkill object
	/// @param skillName The name of the skill
	/// @param skillAbility The ability score used by the skill
	/// @param requiresTraining Indicates if skill can be used at rank 0
	PathfinderSkill(std::string skillName = "Pathfinder Skill",
		CHARACTER_ABILITY skillAbility = INTELLIGENCE, 
		bool requiresTraining = false);

	/// Destroys the PathfinderSkill object
	~PathfinderSkill();

	/// Increases or decreases the number of skill ranks. Total ranks cannot
	/// be negative, so any extra decrease will be discarded.
	/// @param amount The number of ranks to increase or decrease. Negative
	///				  values decrease.
	void addRanks(const int amount);

	/// Gets the number of ranks allocated to this skill
	/// @return The number of ranks
	int getRanks() const { return ranks; }

	/// Toggles the class skill flag
	void toggleClassSkill();

	/// Gets a boolean indicating whether the skill is a class skill
	/// @return true if the skill is a class skill, false otherwise
	bool isClassSkill() const { return classSkill; }

	/// Gets a boolean indicating if the skill requires at least 1 rank to use
	/// @return true if the skill requires ranks, false otherwise
	bool isTrainedOnly() const { return trainedOnly; }

	/// Gets the miscellaneous modifiers
	/// @return The miscellaneous modifier total
	int getModifiers() const { return miscModifiers; }

	/// Increases or decreases the miscellaneous modifiers by the given amount
	/// @param amount The amount of increase or decrease
	void addModifier(const int amount);

	/// Gets the bonus modifier from ranks
	/// @return The modifier amount
	int getRankModifier() const;

	/// Gets the skill as a string
	/// @return The skill as a string
	std::string toString() const;

	/// Gets the skill's associated ability score type
	/// @return The ability score type
	CHARACTER_ABILITY getAbility() const { return linkedAbility; }

	/// Compares two PathfinderSkill objects for equality
	/// @param other The PathfinderSkill being compared to this one
	/// @return true if the operands are equal, false otherwise
	inline bool operator==(const PathfinderSkill &other) {
		return this->name == other.name;
	}

	/// Compares two PathfinderSkill objects for inequality
	/// @param other The PathfinderSkill being compared to this one
	/// @return true if the operands are equal, false otherwise
	inline bool operator!=(const PathfinderSkill &other) {
		return !(operator==(other));
	}

private:
	/// Skill name
	std::string name;

	/// The number of ranks invested
	int ranks;

	/// The primary ability/attribute associated
	CHARACTER_ABILITY linkedAbility;

	/// Flag indicating whether the skill can be used with 0 ranks
	bool trainedOnly;

	/// Flag indicating whether the skill is part of the character's
	/// class package
	bool classSkill;

	/// Miscellaneous modifiers applied via feats, other sources
	int miscModifiers;
};

