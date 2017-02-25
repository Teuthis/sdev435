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
	COLOSSAL,
	GARGANTUAN,
	HUGE,
	LARGE,
	MEDIUM,
	SMALL,
	TINY,
	DIMUNITIVE,
	FINE
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
	LIGHT,
	MEDIUM,
	HEAVY
};