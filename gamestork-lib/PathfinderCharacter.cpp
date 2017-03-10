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
