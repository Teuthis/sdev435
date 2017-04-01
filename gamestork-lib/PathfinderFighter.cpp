#include "PathfinderFighter.h"



PathfinderFighter::PathfinderFighter(const std::string weaponFocusChoice)
	: PathfinderClass(2, 0, 2, 1, 10, 2, SHIELDS | LIGHT_ARMOR | MEDIUM_ARMOR
	| HEAVY_ARMOR | SIMPLE_WEAPONS | MARTIAL_WEAPONS), 
	weaponFocus(weaponFocusChoice)
{
	// mark class skills
	skills[CLIMB].toggleClassSkill();
	skills[KNOWLEDGE_DUNGEONEERING].toggleClassSkill();
	skills[RIDE].toggleClassSkill();
	skills[SWIM].toggleClassSkill();

}


PathfinderFighter::~PathfinderFighter()
{
}

std::vector<std::string> PathfinderFighter::getClassFeatures() const
{
	std::vector<std::string> result;
	result.push_back("Weapon Focus (" + weaponFocus + ")");
	return result;
}

std::vector<std::string> PathfinderFighter::getMagic() const
{
	std::vector<std::string> result;
	result.push_back("Fighters cannot cast spells.");
	return result;
}

int PathfinderFighter::getStartingMoney() const
{
	return 17500;
}

void PathfinderFighter::setWeaponFocus(const std::string weapon)
{
	weaponFocus = weapon;
}

std::string PathfinderFighter::getWeaponFocus() const
{
	return weaponFocus;
}
