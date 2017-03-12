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
	skills.push_back(PathfinderSkill(ACROBATICS, "Acrobatics", DEXTERITY)); 
	skills.push_back(PathfinderSkill(BLUFF, "Bluff", CHARISMA));		
	skills.push_back(PathfinderSkill(CLIMB, "Climb", STRENGTH));		
	skills.push_back(PathfinderSkill(DIPLOMACY, "Diplomacy", CHARISMA));	
	skills.push_back(PathfinderSkill(
		DISABLE_DEVICE, "Disable Device", DEXTERITY, true));
	skills.push_back(PathfinderSkill(HEAL, "Heal", WISDOM));
	skills.push_back(PathfinderSkill(
		KNOWLEDGE_ARCANA, "Knowledge Arcana", INTELLIGENCE, true));
	skills.push_back(PathfinderSkill(
		KNOWLEDGE_DUNGEONEERING, "Knowledge Dungeoneering", INTELLIGENCE, true));
	skills.push_back(PathfinderSkill(
		KNOWLEDGE_GEOGRAPHY, "Knowledge Geography", INTELLIGENCE, true));
	skills.push_back(PathfinderSkill(
		KNOWLEDGE_HISTORY, "Knowledge History", INTELLIGENCE, true));
	skills.push_back(PathfinderSkill(
		KNOWLEDGE_LOCAL, "Knowledge Local", INTELLIGENCE, true));
	skills.push_back(PathfinderSkill(
		KNOWLEDGE_NATURE, "Knowledge Nature", INTELLIGENCE, true));
	skills.push_back(PathfinderSkill(
		KNOWLEDGE_RELIGION, "Knowledge Religion", INTELLIGENCE, true));
	skills.push_back(PathfinderSkill(PERCEPTION, "Perception", WISDOM));
	skills.push_back(PathfinderSkill(RIDE, "Ride", DEXTERITY));
	skills.push_back(PathfinderSkill(SENSE_MOTIVE, "Sense Motive", WISDOM));
	skills.push_back(PathfinderSkill(
		SPELLCRAFT, "Spellcraft", INTELLIGENCE, true));
	skills.push_back(PathfinderSkill(STEALTH, "Stealth", DEXTERITY));
	skills.push_back(PathfinderSkill(SWIM, "Swim", STRENGTH));
}


