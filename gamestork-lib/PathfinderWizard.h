#pragma once
#include "PathfinderClass.h"
class PathfinderWizard :
	public PathfinderClass
{
public:
	PathfinderWizard(const std::string arcaneSchool = "Universalist");
	~PathfinderWizard();

	/// Returns a string representation of the object
	/// @return The object as string
	std::string toString() const { return "Wizard"; }

	/// Returns an integer representation of the object
	/// @return The CHARACTER_CLASS associated with the object
	CHARACTER_CLASS toClassType() const { return WIZARD; }

	/// Returns a collection of strings representing class features
	/// @return The list of features
	std::vector<std::string> getClassFeatures() const;

	/// Gets the information to display in the Spells/Magic section
	/// @return A vector of strings to populate the Magic box
	std::vector<std::string> getMagic() const;

	/// Sets a spell to be known
	/// @param spell The spell to learn
	void learnSpell(const WIZARD_SPELLS spell);

	/// Sets a spell to be unknown
	/// @param spell The spell to remove from the spell book
	void unlearnSpell(const WIZARD_SPELLS spell);

	/// Returns the total number of known spells
	/// @return The total number of known spells
	int knownSpellCount() const;

	/// Returns a bool indicating whether a given spell is known
	/// @param spell The spell to check
	/// @return true if the spell is known, false otherwise
	bool isSpellKnown(const WIZARD_SPELLS spell) const;

	/// Returns the default starting currency for the class
	/// @return The amount of money a character of this class begins with
	int getStartingMoney() const;

private:
	/// Magical specialty
	std::string school;

	/// Spell names list
	std::vector<std::string> spellNames;

	/// Known spells
	std::vector<bool> spellbook;
};

