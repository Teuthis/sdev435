#include "PathfinderCharacter.h"



PathfinderCharacter::PathfinderCharacter(CHARACTER_CLASS chosenClass)
	: name(""), alignment(), race(), charClass(),
	abilityScores(), feats(), inventory(), money(0)
{
	switch (chosenClass) {
	case FIGHTER:
		charClass = std::make_unique<PathfinderFighter>(PathfinderFighter());
		break;
	case CLERIC:
		charClass = std::make_unique<PathfinderCleric>(PathfinderCleric ());
		break;
	case ROGUE:
		charClass = std::make_unique<PathfinderRogue>(PathfinderRogue());
		break;
	case WIZARD:
		charClass = std::make_unique<PathfinderWizard>(PathfinderWizard());
		break;
	}
	abilityScores.insert(std::pair<CHARACTER_ABILITY, int>(STRENGTH, 3));
	abilityScores.insert(std::pair<CHARACTER_ABILITY, int>(DEXTERITY, 3));
	abilityScores.insert(std::pair<CHARACTER_ABILITY, int>(CONSTITUTION, 3));
	abilityScores.insert(std::pair<CHARACTER_ABILITY, int>(INTELLIGENCE, 3));
	abilityScores.insert(std::pair<CHARACTER_ABILITY, int>(WISDOM, 3));
	abilityScores.insert(std::pair<CHARACTER_ABILITY, int>(CHARISMA, 3));

	money = charClass->getStartingMoney();
}


PathfinderCharacter::~PathfinderCharacter()
{
}

int PathfinderCharacter::getGoldPieces() const
{
	return money / 100;
}

int PathfinderCharacter::getSilverPieces() const
{
	return (money % 100) / 10;
}

int PathfinderCharacter::getCopperPieces() const
{
	return money % 10;
}

bool PathfinderCharacter::buyItem(const InventoryItem item)
{
	if ((money - item.getValue()) >= 0) {
		money -= item.getValue();
		inventory.push_back(item);
		return true;
	}
	return false;
}

std::string PathfinderCharacter::getName() const
{
	return name;
}

void PathfinderCharacter::setName(const std::string newName)
{
	name = newName;
}

ALIGNMENT PathfinderCharacter::getAlignment() const
{
	return alignment;
}

void PathfinderCharacter::setAlignment(ALIGNMENT newAlign)
{
	alignment = newAlign;
}

std::string PathfinderCharacter::getRace() const
{
	return race->toString();
}

int PathfinderCharacter::getRaceId() const
{
	if (race == NULL) {
		return -1;
	} 
	return race->toInt();
}

void PathfinderCharacter::setRace(CHARACTER_RACE newRace)
{
	switch (newRace) {
	case HUMAN:
		race = std::make_unique<PathfinderHuman>(PathfinderHuman());
		break;
	case ELF:
		race = std::make_unique<PathfinderElf>(PathfinderElf());
		break;
	case DWARF:
		race = std::make_unique<PathfinderDwarf>(PathfinderDwarf());
		break;
	}
}

int PathfinderCharacter::getAbilityScore(CHARACTER_ABILITY ability) const
{
	int result = abilityScores.at(ability);
	if (race != NULL) 
		result += race->abilityBonus(ability);
	return result;
}

int PathfinderCharacter::getRawAbilityScore(CHARACTER_ABILITY ability) const
{
	return abilityScores.at(ability);
}

int PathfinderCharacter::getAbilityBonusMod(CHARACTER_ABILITY ability) const
{
	switch (getAbilityScore(ability)) {
	case 1:
		return -5;
	case 2:
	case 3:
		return -4;
	case 4:
	case 5:
		return -3;
	case 6:
	case 7:
		return -2;
	case 8:
	case 9:
		return -1;
	case 10:
	case 11:
		return 0;
	case 12:
	case 13:
		return 1;
	case 14:
	case 15:
		return 2;
	case 16:
	case 17:
		return 3;
	case 18:
	case 19:
		return 4;
	case 20:
		return 5;
	default:
		return 0;
	}
}

void PathfinderCharacter::setAbility(CHARACTER_ABILITY ability, const int value)
{
	abilityScores[ability] = value;
}

int PathfinderCharacter::getRemainingFeatCount() const
{
	int total = 1;
	if (race != NULL) {
		total += race->getBonusFeats();
	}
	return total - static_cast<int>(feats.size());
}

int PathfinderCharacter::getRemainingSkillRanks() const
{
	int total = charClass->getUnspentSkillRanks(getAbilityBonusMod(INTELLIGENCE));
	if (race != NULL) {
		total += race->getBonusSkillRanks();
	}
	return total;
}
