#include "PathfinderCleric.h"



PathfinderCleric::PathfinderCleric(const std::string deity)
	: PathfinderClass(2, 0, 2, 0, 8, 2, SHIELDS | LIGHT_ARMOR | MEDIUM_ARMOR
	| SIMPLE_WEAPONS), chosenDeity(deity)
{
	// mark class skills
	skills[DIPLOMACY].toggleClassSkill();
	skills[HEAL].toggleClassSkill();
	skills[KNOWLEDGE_ARCANA].toggleClassSkill();
	skills[KNOWLEDGE_HISTORY].toggleClassSkill();
	skills[KNOWLEDGE_RELIGION].toggleClassSkill();
	skills[SENSE_MOTIVE].toggleClassSkill();
	skills[SPELLCRAFT].toggleClassSkill();
}


PathfinderCleric::~PathfinderCleric()
{
}

std::vector<std::string> PathfinderCleric::getClassFeatures() const
{
	std::vector<std::string> result;
	result.push_back("God: " + chosenDeity);
	if (chosenDeity == "Desna") {
		result.push_back("Holy Weapon: Starknife");
		result.push_back("Agile Feet: 3 + WIS per day");
		result.push_back("Bit of Luck: 3 + WIS per day");
	} else if (chosenDeity == "Gorum") {
		result.push_back("Holy Weapon: Longsword");
		result.push_back("Battle Rage: 3 + WIS per day");
		result.push_back("Strength Surge: 3 + WIS per day");
	} else if (chosenDeity == "Sarenrae") {
		result.push_back("Holy Weapon: Scimitar");
		result.push_back("Rebuke Death: 3 + WIS per day");
		result.push_back("Sun's Blessing");
	}
	result.push_back("Channel Energy 1d6: 3 + CHA per day");
	return result;
}

std::vector<std::string> PathfinderCleric::getMagic() const
{
	std::vector<std::string> result;
	result.push_back("Unlimited orisons per day");
	result.push_back("Prepare two 1st-level cleric spells");
	return result;
}
