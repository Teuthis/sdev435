#include "PathfinderRogue.h"



PathfinderRogue::PathfinderRogue()
	: PathfinderClass(0, 2, 0, 0, 8, 8, LIGHT_ARMOR | SIMPLE_WEAPONS)
{
	// mark class skills
	skills[ACROBATICS].toggleClassSkill();
	skills[BLUFF].toggleClassSkill();
	skills[CLIMB].toggleClassSkill();
	skills[DIPLOMACY].toggleClassSkill();
	skills[DISABLE_DEVICE].toggleClassSkill();
	skills[KNOWLEDGE_DUNGEONEERING].toggleClassSkill();
	skills[KNOWLEDGE_LOCAL].toggleClassSkill();
	skills[PERCEPTION].toggleClassSkill();
	skills[SENSE_MOTIVE].toggleClassSkill();
	skills[STEALTH].toggleClassSkill();
	skills[SWIM].toggleClassSkill();
}


PathfinderRogue::~PathfinderRogue()
{
}

std::vector<std::string> PathfinderRogue::getClassFeatures() const
{
	std::vector<std::string> result;
	result.push_back("Sneak Attack +1d6");
	result.push_back("Trapfinding +1");
	return result;
}

std::vector<std::string> PathfinderRogue::getMagic() const
{
	std::vector<std::string> result;
	result.push_back("Rogues cannot cast spells.");
	return result;
}

int PathfinderRogue::getStartingMoney() const
{
	return 14000;
}
