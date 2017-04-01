#include "PathfinderCharacter.h"



PathfinderCharacter::PathfinderCharacter(CHARACTER_CLASS chosenClass)
	: name(""), gender(MALE), alignment(), race(), charClass(),
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

PathfinderCharacter::PathfinderCharacter(const PathfinderCharacter & other)
	: name(other.name), gender(other.gender), race(), charClass(),
	abilityScores(other.abilityScores), feats(other.feats), 
	inventory(other.inventory), money(other.money)
{
	switch (other.getClassId()) {
	case CLERIC:
	{
		PathfinderCleric* cleric = dynamic_cast<PathfinderCleric*>(
			other.charClass.get());
		charClass = std::make_unique<PathfinderCleric>(
			PathfinderCleric(*cleric));
		break;
	}
	case FIGHTER:
	{
		PathfinderFighter* fighter = dynamic_cast<PathfinderFighter*>(
			other.charClass.get());
		charClass = std::make_unique<PathfinderFighter>(
			PathfinderFighter(*fighter));
		break;
	}
	case ROGUE:
	{
		PathfinderRogue* rogue = dynamic_cast<PathfinderRogue*>(
			other.charClass.get());
		charClass = std::make_unique<PathfinderRogue>(
			PathfinderRogue(*rogue));
		break;
	}
	case WIZARD:
	{
		PathfinderWizard* wizard = dynamic_cast<PathfinderWizard*>(
			other.charClass.get());
		charClass = std::make_unique<PathfinderWizard>(
			PathfinderWizard(*wizard));
		break;
	}
	}

	switch (other.getRaceId()) {
	case HUMAN:
		race = std::make_unique<PathfinderHuman>(PathfinderHuman(
			*(dynamic_cast<PathfinderHuman*>(other.race.get()))));
		break;
	case ELF:
		race = std::make_unique<PathfinderElf>(PathfinderElf());
		break;
	case DWARF:
		race = std::make_unique<PathfinderDwarf>(PathfinderDwarf());
		break;
	}
}

PathfinderCharacter & PathfinderCharacter::operator=(const PathfinderCharacter & other)
{
	if (&other == this) {
		return *this;
	}
	
	name = other.name;
	gender = other.gender;
	abilityScores = other.abilityScores;
	feats = other.feats;
	inventory = other.inventory;
	money = other.money;

	switch (other.getClassId()) {
	case CLERIC:
	{
		PathfinderCleric* cleric = dynamic_cast<PathfinderCleric*>(
			other.charClass.get());
		charClass = std::make_unique<PathfinderCleric>(
			PathfinderCleric(*cleric));
		break;
	}
	case FIGHTER:
	{
		PathfinderFighter* fighter = dynamic_cast<PathfinderFighter*>(
			other.charClass.get());
		charClass = std::make_unique<PathfinderFighter>(
			PathfinderFighter(*fighter));
		break;
	}
	case ROGUE:
	{
		PathfinderRogue* rogue = dynamic_cast<PathfinderRogue*>(
			other.charClass.get());
		charClass = std::make_unique<PathfinderRogue>(
			PathfinderRogue(*rogue));
		break;
	}
	case WIZARD:
	{
		PathfinderWizard* wizard = dynamic_cast<PathfinderWizard*>(
			other.charClass.get());
		charClass = std::make_unique<PathfinderWizard>(
			PathfinderWizard(*wizard));
		break;
	}
	}

	switch (other.getRaceId()) {
	case HUMAN:
		race = std::make_unique<PathfinderHuman>(PathfinderHuman(
			*(dynamic_cast<PathfinderHuman*>(other.race.get()))));
		break;
	case ELF:
		race = std::make_unique<PathfinderElf>(PathfinderElf());
		break;
	case DWARF:
		race = std::make_unique<PathfinderDwarf>(PathfinderDwarf());
		break;
	}

	return *this;
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

bool PathfinderCharacter::buyItem(const std::shared_ptr<InventoryItem> item)
{
	if ((money - item->getValue()) >= 0) {
		money -= item->getValue();
		inventory.push_back(item);
		return true;
	}
	return false;
}

bool PathfinderCharacter::removeItem(const int index)
{
	if (index < 0 || index >= inventory.size()) {
		return false;
	}
	auto item = inventory.at(index);
	money += item->getValue();
	inventory.erase(inventory.begin() + index);
	return true;
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

CHARACTER_CLASS PathfinderCharacter::getClassId() const
{
	return charClass->toClassType();
}

std::string PathfinderCharacter::getClassName() const
{
	return charClass->toString();
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

int PathfinderCharacter::getHitpoints() const
{
	return charClass->getBaseHitPoints();
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

int PathfinderCharacter::getCharacterStatistic(CHARACTER_STATISTIC statistic) const
{
	switch (statistic) {
	case ATTACK_BONUS:
		return charClass->getAttackBonus();
	case FORTITUDE_SAVE:
		return charClass->getFortitudeBonus();
	case REFLEX_SAVE:
		return charClass->getReflexBonus();
	case WILL_SAVE:
		return charClass->getWillBonus();
	default:
		return 0;
	}
}

int PathfinderCharacter::getProficiencies() const
{
	return charClass->getProficiencies();
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

const std::vector<PathfinderSkill> PathfinderCharacter::getUntrainedSkills() const
{
	std::vector<PathfinderSkill> untrained;
	for (auto skill : charClass->getSkills()) {
		if (skill.getRanks() == 0) {
			untrained.push_back(skill);
		}
	}
	return untrained;
}

void PathfinderCharacter::trainSkill(const CHARACTER_SKILLS skill)
{
	charClass->addSkillRank(skill);
}

void PathfinderCharacter::untrainSkill(const CHARACTER_SKILLS skill)
{
	charClass->removeSkillRank(skill);
}

void PathfinderCharacter::addFeat(const PathfinderFeat feat)
{
	feats.push_back(feat);
}

void PathfinderCharacter::removeFeat(const int index)
{
	if (index >= 0 && index < feats.size()) {
		feats.erase(feats.begin() + index);
	}
}

void PathfinderCharacter::changeHumanBonus(CHARACTER_ABILITY ability)
{
	if (race == NULL || race->toInt() != HUMAN) {
		throw std::logic_error("Cannot call changeHumanBonus() on nonhumans");
	}
	race = std::make_unique<PathfinderHuman>(PathfinderHuman(ability));
}

void PathfinderCharacter::setGender(const GENDER newGender)
{
	gender = newGender;
}

GENDER PathfinderCharacter::getGender() const
{
	return gender;
}

void PathfinderCharacter::setClassSpecificValue(const std::string value)
{
	switch (charClass->toClassType()) {
	case CLERIC:
		dynamic_cast<PathfinderCleric*>(charClass.get())->setPatron(value);
		break;
	case FIGHTER:
		dynamic_cast<PathfinderFighter*>(
			charClass.get())->setWeaponFocus(value);
		break;
	case WIZARD:
		dynamic_cast<PathfinderWizard*>(
			charClass.get())->setArcaneSchool(value);
		break;
	default:
		throw std::logic_error(
			"setClassSpecificValue cannot be called on classes with no special string values");
		break;
	}
}

void PathfinderCharacter::addWizardSpell(const WIZARD_SPELLS spell)
{
	if (charClass->toClassType() != WIZARD) {
		throw std::logic_error(
			"addWizardSpell should only be called on wizards.");
	}
	dynamic_cast<PathfinderWizard*>(
		charClass.get())->learnSpell(spell);
}

void PathfinderCharacter::removeWizardSpell(const WIZARD_SPELLS spell)
{
	if (charClass->toClassType() != WIZARD) {
		throw std::logic_error(
			"addWizardSpell should only be called on wizards.");
	}
	dynamic_cast<PathfinderWizard*>(
		charClass.get())->unlearnSpell(spell);
}

bool PathfinderCharacter::knowsSpell(const WIZARD_SPELLS spell) const
{
	if (charClass->toClassType() != WIZARD) {
		return false;
	}
	return dynamic_cast<PathfinderWizard*>(
		charClass.get())->isSpellKnown(spell);
}

int PathfinderCharacter::spellSlotsRemaining() const
{
	if (charClass->toClassType() == WIZARD) {
		int maxSpells = 3 + getAbilityBonusMod(INTELLIGENCE);
		return maxSpells - dynamic_cast<PathfinderWizard*>(
			charClass.get())->knownSpellCount();
	}
	return 0;
}

XmlDocument pathfinderCharacterToXml(const PathfinderCharacter & character)
{
	XmlNode charNode("pathfinderCharacter");

	charNode.setAttribute("rulesVersion", "beginner");
	charNode.setAttribute("name", character.getName());
	charNode.setAttribute("alignment", std::to_string(
		character.getAlignment()));
	charNode.setAttribute("gender", std::to_string(character.getGender()));

	XmlNode raceNode("race");
	raceNode.setInnerValue(character.getRace());
	if (character.getRaceId() == HUMAN) {
		raceNode.setAttribute("abilityBonus", std::to_string(
			dynamic_cast<PathfinderHuman*>(
				character.race.get())->getHumanAbility()));
	}
	charNode.addChild(raceNode);

	XmlNode classNode(character.getClassName());
	classNode.setAttribute("level", "1");
	classNode.setAttribute("hp", std::to_string(character.getHitpoints()));
	switch (character.getClassId()) {
	case CLERIC:
	{
		PathfinderCleric* cleric = dynamic_cast<PathfinderCleric*>(
			character.charClass.get());
		classNode.addChild("patronGod", cleric->getPatron());
		break;
	}
	case FIGHTER:
	{
		PathfinderFighter* fighter = dynamic_cast<PathfinderFighter*>(
			character.charClass.get());
		classNode.addChild("weaponFocus", fighter->getWeaponFocus());
		break;
	}
	case WIZARD:
	{
		PathfinderWizard* wizard = dynamic_cast<PathfinderWizard*>(
			character.charClass.get());
		classNode.addChild("arcaneSchool", wizard->getArcaneSchool());
		for (int i = 0; i <= SLEEP; i++) {
			if (character.knowsSpell(static_cast<WIZARD_SPELLS>(i))) {
				classNode.addChild("spell", std::to_string(i));
			}
		}
		break;
	}
	}
	charNode.addChild(classNode);

	XmlNode skillsNode("skills");
	for (int i = 0; i <= SWIM; i++) {
		if (character.charClass->getSkills()[i].getRanks() > 0) {
			skillsNode.addChild("skill", std::to_string(i));
		}
	}
	charNode.addChild(skillsNode);

	XmlNode featNode("feats");
	for (auto feat : character.feats) {
		featNode.addChild("feat", feat.toString());
	}
	charNode.addChild(featNode);

	XmlNode inventoryNode("inventory");
	inventoryNode.setAttribute("money", std::to_string(character.money));
	for (auto item : character.inventory) {
		switch (item->getItemType()) {
		case 0:
		{
			XmlNode itemNode("item");
			itemNode.setAttribute("value", std::to_string(item->getValue()));
			itemNode.setInnerValue(item->getName());
			inventoryNode.addChild(itemNode);
			break;
		}
		case 1:
		{
			XmlNode armorNode("armor");
			armorNode.setInnerValue(item->getName());
			armorNode.setAttribute("value", std::to_string(item->getValue()));
			armorNode.setAttribute("ac", std::to_string(
				dynamic_cast<PathfinderArmor*>(item.get())->getACModifier()));
			inventoryNode.addChild(armorNode);
			break;
		}
		case 2:
		{
			XmlNode weaponNode("weapon");
			weaponNode.setInnerValue(item->getName());
			weaponNode.setAttribute("value", std::to_string(item->getValue()));
			weaponNode.setAttribute("damage", dynamic_cast<PathfinderWeapon*>(
				item.get())->getDamage());
			inventoryNode.addChild(weaponNode);
			break;
		}
		}
	}
	charNode.addChild(inventoryNode);

	XmlDocument doc;
	doc.setRoot(charNode);
	return doc;
}

PathfinderCharacter xmlToPathfinderCharacter(const XmlDocument& xml) {
	xml;
	return PathfinderCharacter(FIGHTER);
}