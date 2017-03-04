//-----------------------------------------------------------------------------
/**
File: PathfinderClass.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Implementation file for Pathfinder character class abstract class
Overlapping terminology. Character class == occupation
*/
//-----------------------------------------------------------------------------

#include "PathfinderClass.h"

int PathfinderClass::getUnspentSkillRanks(const int intelligenceModifier) const
{
	int spent = 0;
	for (auto skill : skills) {
		spent += skill.getRanks();
	}
	return baseSkillRanks + intelligenceModifier - spent;
}

int PathfinderClass::getBaseHitPoints() const
{
	return hp;
}

int PathfinderClass::getFortitudeBonus() const
{
	return fortitudeMod;
}

int PathfinderClass::getReflexBonus() const
{
	return reflexMod;
}

int PathfinderClass::getWillBonus() const
{
	return willMod;
}

int PathfinderClass::getAttackBonus() const
{
	return attackBonus;
}

bool PathfinderClass::addSkillRank(const CHARACTER_SKILLS skill)
{
	if (skills[skill].getRanks() == 0) {
		skills[skill].addRanks(1);
		return true;
	}
	return false;
}


bool PathfinderClass::removeSkillRank(const CHARACTER_SKILLS skill)
{
	if (skills[skill].getRanks() == 1) {
		skills[skill].addRanks(-1);
		return true;
	}
	return false;
}

const std::vector<PathfinderSkill> PathfinderClass::getSkills() const
{
	return skills;
}

PathfinderClass::PathfinderClass(const int fortitude, const int reflex,
	const int will, const int attack, const int hitpoints, const int baseRanks,
	const int proficiencies)
	: skills(), fortitudeMod(fortitude), reflexMod(reflex), willMod(will),
	attackBonus(attack), hp(hitpoints), baseSkillRanks(baseRanks), 
	weaponArmorProficiencies(proficiencies)
{
	skills.push_back(PathfinderSkill("Acrobatics", DEXTERITY)); 
	skills.push_back(PathfinderSkill("Bluff", CHARISMA));		
	skills.push_back(PathfinderSkill("Climb", STRENGTH));		
	skills.push_back(PathfinderSkill("Diplomacy", CHARISMA));	
	skills.push_back(PathfinderSkill("Disable Device", DEXTERITY, true));
	skills.push_back(PathfinderSkill("Heal", WISDOM));
	skills.push_back(PathfinderSkill("Knowledge Arcana", INTELLIGENCE, true));
	skills.push_back(PathfinderSkill("Knowledge Dungeoneering", INTELLIGENCE, true));
	skills.push_back(PathfinderSkill("Knowledge Geography", INTELLIGENCE, true));
	skills.push_back(PathfinderSkill("Knowledge History", INTELLIGENCE, true));
	skills.push_back(PathfinderSkill("Knowledge Local", INTELLIGENCE, true));
	skills.push_back(PathfinderSkill("Knowledge Nature", INTELLIGENCE, true));
	skills.push_back(PathfinderSkill("Knowledge Religion", INTELLIGENCE, true));
	skills.push_back(PathfinderSkill("Perception", WISDOM));
	skills.push_back(PathfinderSkill("Ride", DEXTERITY));
	skills.push_back(PathfinderSkill("Sense Motive", WISDOM));
	skills.push_back(PathfinderSkill("Spellcraft", INTELLIGENCE, true));
	skills.push_back(PathfinderSkill("Stealth", DEXTERITY));
	skills.push_back(PathfinderSkill("Swim", STRENGTH));
}


