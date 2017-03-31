//-----------------------------------------------------------------------------
/**
File: PathfinderEnumerations.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken, Jason Roberge 2017

Description: Enums specific to Pathfinder rules system
*/
//-----------------------------------------------------------------------------

#pragma once

/// Possible philosophical alignments for sapients
enum ALIGNMENT
{
	LAWFUL_GOOD,
	NEUTRAL_GOOD,
	CHAOTIC_GOOD,
	LAWFUL_NEUTRAL,
	TRUE_NEUTRAL,
	CHAOTIC_NEUTRAL,
	LAWFUL_EVIL,
	NEUTRAL_EVIL,
	CHAOTIC_EVIL
};

/// Possible sizes of characters and monsters
enum CREATURE_SIZE
{
	SIZE_COLOSSAL,
	SIZE_GARGANTUAN,
	SIZE_HUGE,
	SIZE_LARGE,
	SIZE_MEDIUM,
	SIZE_SMALL,
	SIZE_TINY,
	SIZE_DIMUNITIVE,
	SIZE_FINE
};

/// Character ability score (attribute) types
enum CHARACTER_ABILITY
{
	STRENGTH,
	DEXTERITY,
	CONSTITUTION,
	INTELLIGENCE,
	WISDOM,
	CHARISMA
};

/// Non-ability statistic types
enum CHARACTER_STATISTIC
{
	ATTACK_BONUS,
	FORTITUDE_SAVE,
	REFLEX_SAVE,
	WILL_SAVE
};

/// Weapon and armor proficiencies
/// Usable as bit flags
enum PROFICIENCY
{
	SIMPLE_WEAPONS = 1,
	MARTIAL_WEAPONS = 2,
	LIGHT_ARMOR = 4,
	MEDIUM_ARMOR = 8,
	HEAVY_ARMOR = 16,
	SHIELDS = 32
};

/// Major weight category of armors
enum ARMOR_WEIGHTCLASS
{
	NONE,
	LIGHT_WEIGHT,
	MEDIUM_WEIGHT,
	HEAVY_WEIGHT
};

/// Character classes
enum CHARACTER_CLASS
{
	FIGHTER = 1,
	ROGUE = 2,
	CLERIC = 4,
	WIZARD = 8
};

/// Character races
enum CHARACTER_RACE
{
	HUMAN = 0,
	ELF = 1,
	DWARF = 2
};

/// Skills
enum CHARACTER_SKILLS
{
	ACROBATICS = 0,
	BLUFF,
	CLIMB,
	DIPLOMACY,
	DISABLE_DEVICE,
	HEAL,
	KNOWLEDGE_ARCANA,
	KNOWLEDGE_DUNGEONEERING,
	KNOWLEDGE_GEOGRAPHY,
	KNOWLEDGE_HISTORY,
	KNOWLEDGE_LOCAL,
	KNOWLEDGE_NATURE,
	KNOWLEDGE_RELIGION,
	PERCEPTION,
	RIDE,
	SENSE_MOTIVE,
	SPELLCRAFT,
	STEALTH,
	SWIM
};

/// Spells
enum WIZARD_SPELLS {
	ALARM = 0,
	BURNING_HANDS,
	CAUSE_FEAR,
	CHARM_PERSON,
	DETECT_SECRET_DOORS,
	DISGUISE_SELF,
	FEATHER_FALL,
	MAGE_ARMOR,
	MAGIC_MISSILE,
	SLEEP
};

/// Gender options
enum GENDER {
	MALE = 0,
	FEMALE,
	OTHER,
	NOGENDER
};