#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "PathfinderEnumerations.h"
#include "PathfinderHuman.h"
#include "PathfinderDwarf.h"
#include "PathfinderElf.h"
#include "PathfinderFighter.h"
#include "PathfinderCleric.h"
#include "PathfinderRogue.h"
#include "PathfinderWizard.h"
#include "PathfinderFeat.h"
#include "PathfinderArmor.h"
#include "PathfinderWeapon.h"
#include "InventoryItem.h"
#include "XmlDocument.h"

class PathfinderCharacter
{
public:
	// Parameterless ctor prohibited
	PathfinderCharacter() = delete;

	/// Constructs a new PathfinderCharacter object
	/// @param characterClass The class of the character being created
	PathfinderCharacter(CHARACTER_CLASS chosenClass);

	/// Destroys the PathfinderCharacter object
	~PathfinderCharacter();

	/// Copy constructor
	/// @param other The object to copy from
	PathfinderCharacter(const PathfinderCharacter& other);

	/// Assignment operator
	/// @param other The object to copyassign from
	PathfinderCharacter& operator=(const PathfinderCharacter& other);

	/// Gets the number of gold pieces the character possesses
	/// @return The number of gold pieces (1 gp == 10 sp == 100 cp)
	int getGoldPieces() const;

	/// Gets the number of silver pieces the character possesses
	/// @return The number of silver pieces (1 sp == 10 cp, 10 sp == 1 gp)
	int getSilverPieces() const;

	/// Gets the number of copper pieces the character possesses
	/// @return The number of copper pieces (10 cp == 1 sp, 100 cp == 1 gp)
	int getCopperPieces() const;

	/// Attempts to add an item to the character's inventory, provided the 
	/// character has enough money to purchase the item
	/// @param item The item to add to inventory
	/// @return true if the item was successfully purchased, 
	///			false if insufficient funds
	bool buyItem(const std::shared_ptr<InventoryItem> item);

	/// Removes the item at the specified index from the character's inventory
	/// and refunds the cost
	/// @param index The index to remove from
	/// @return true if the item existed and was removed, false otherwise
	bool removeItem(const int index);

	/// Gets a list of inventory items
	/// @return A vector of pointers to items
	std::vector<std::shared_ptr<InventoryItem>> getInventory() const;

	/// Gets the character's name
	/// @return The character's name
	std::string getName() const;

	/// Sets the character's name
	/// @param newName The new name value to set
	void setName(const std::string newName);

	/// Gets the character's philosophical alignment
	/// @return The alignment value
	ALIGNMENT getAlignment() const;

	/// Sets the character's philosophical alignment
	/// @param newAlign The new alignment value
	void setAlignment(ALIGNMENT newAlign);

	/// Gets the character's occupational class id
	/// @return The class id
	CHARACTER_CLASS getClassId() const;

	/// Gets the character's occupation class name
	/// @return The class as std::string
	std::string getClassName() const;

	/// Gets the character's race/species
	/// @return The race as string
	std::string getRace() const;

	/// Gets the character's race/species
	/// @return The race as int
	int getRaceId() const;

	/// Sets the character's race/species
	/// @param newRace The new race value
	void setRace(CHARACTER_RACE newRace);

	/// Gets the character's hit points
	/// @return The number of hit points
	int getHitpoints() const;

	/// Gets the requested ability score
	/// @param ability The requested ability
	/// @return The ability score
	int getAbilityScore(CHARACTER_ABILITY ability) const;

	/// Gets the requested ability score without racial or other bonuses
	/// (Effectively, the original rolled value)
	/// @param ability The requested ability
	/// @return The ability score bereft of bonuses
	int getRawAbilityScore(CHARACTER_ABILITY ability) const;

	/// Gets the bonus modifier for the requested ability
	/// @param ability The requested ability
	/// @return The ability bonus modifier
	int getAbilityBonusMod(CHARACTER_ABILITY ability) const;

	/// Sets the specified ability score
	/// @param ability The ability to change
	/// @param value The new ability score value
	void setAbility(CHARACTER_ABILITY ability, const int value);

	/// Gets the requested statistic bonus (saves, attack)
	/// @param statistic The requested statistic
	/// @return The statistic bonus
	int getCharacterStatistic(CHARACTER_STATISTIC statistic) const;

	/// Gets the weapons and armor the character is proficient in
	/// @return A bitmask of the character's proficiencies
	int getProficiencies() const;

	/// Returns the remaining number of feats the character may have
	/// @return The maximum feats less the number taken
	int getRemainingFeatCount() const;

	/// Returns the remaining number of skill ranks the character may have
	/// @return The number of unspent skill ranks
	int getRemainingSkillRanks() const;

	/// Retrieves a list of untrained skills
	/// @return A vector containing the skills the character has 0 ranks in
	const std::vector<PathfinderSkill> getUntrainedSkills() const;

	/// Trains a character in the specified skill
	/// @param skill The identifier of the skill to rank up
	void trainSkill(const CHARACTER_SKILLS skill);

	/// Removes a skill from the character's trained skills
	/// @param skill The identifier of the skill to rank down
	void untrainSkill(const CHARACTER_SKILLS skill);

	/// Gets the requested skill
	/// @param skill The identifier of the skill to get
	/// @return The requested skill
	PathfinderSkill getSkill(const CHARACTER_SKILLS skill) const;

	/// Adds the given feat to the character's known feats
	/// @param feat The feat to add
	void addFeat(const PathfinderFeat feat);

	/// Removes the feat with the given index
	/// @param index The index of the feat to remove
	void removeFeat(const int index);

	/// Gets the list of known feats
	/// @return A vector containing the character's known feats
	std::vector<PathfinderFeat> getFeats() const;

	/// Changes the human racial bonus ability
	/// @param ability The new ability to get the bonus
	/// @throws std::logic_error if this function is called when race isn't human
	void changeHumanBonus(CHARACTER_ABILITY ability);

	/// Changes the character's gender setting
	/// @param newGender The new gender
	void setGender(const GENDER newGender);

	/// Gets the character's gender setting
	/// @return The character's gender
	GENDER getGender() const;

	/// Sets a class-specific string value
	/// @param value The new value
	/// @throws std::logic_error if this function is called on a rogue
	void setClassSpecificValue(const std::string value);

	/// Adds a wizard spell to the character's spellbook
	/// @param spell The spell to add
	/// @throws std::logic_error if the character is not a wizard
	void addWizardSpell(const WIZARD_SPELLS spell);

	/// Removes a wizard spell to the character's spellbook
	/// @param spell The spell to remove
	/// @throws std::logic_error if the character is not a wizard
	void removeWizardSpell(const WIZARD_SPELLS spell);

	/// Checks whether a spell is known
	/// @param spell The spell to test for
	/// @return true if the spell is known, false otherwise
	bool knowsSpell(const WIZARD_SPELLS spell) const;

	/// Gets the number of spell slots a character has available
	/// @return The number of wizard spells the character can learn
	int spellSlotsRemaining() const;

private:
	std::string name;

	GENDER gender;

	ALIGNMENT alignment;

	std::unique_ptr<PathfinderRace> race;

	std::unique_ptr<PathfinderClass> charClass;

	std::map<CHARACTER_ABILITY, int> abilityScores;

	std::vector<PathfinderFeat> feats;

	std::vector<std::shared_ptr<InventoryItem>> inventory;

	int money;

	/// Converts a PathfinderCharacter object to an XmlDocument for saving to disk
	/// @param character A reference to the PathfinderCharacter object
	/// @return An XML representation of the character
	friend XmlDocument pathfinderCharacterToXml(
		const PathfinderCharacter & character);

	/// Creates a PathfinderCharacter object from the provided XML data
	/// @param xml A reference to the XML data
	/// @return A PathfinderCharacter object built from the XML data
	friend PathfinderCharacter* xmlToPathfinderCharacter(const XmlDocument& xml);
};

