#include "PathfinderWizard.h"


PathfinderWizard::PathfinderWizard(const std::string arcaneSchool)
	: PathfinderClass(0, 0, 2, 0, 6, 2, 0), school(arcaneSchool),
	spellNames(10), spellbook(10, false)
{
	// mark class skills
	skills[KNOWLEDGE_ARCANA].toggleClassSkill();
	skills[KNOWLEDGE_DUNGEONEERING].toggleClassSkill();
	skills[KNOWLEDGE_GEOGRAPHY].toggleClassSkill();
	skills[KNOWLEDGE_HISTORY].toggleClassSkill();
	skills[KNOWLEDGE_LOCAL].toggleClassSkill();
	skills[KNOWLEDGE_NATURE].toggleClassSkill();
	skills[KNOWLEDGE_RELIGION].toggleClassSkill();
	skills[SPELLCRAFT].toggleClassSkill();

	// initialize spell names
	spellNames[ALARM] = "Alarm";
	spellNames[BURNING_HANDS] = "Burning Hands";
	spellNames[CAUSE_FEAR] = "Cause Fear";
	spellNames[CHARM_PERSON] = "Charm Person";
	spellNames[DETECT_SECRET_DOORS] = "Detect Secret Doors";
	spellNames[DISGUISE_SELF] = "Disguise Self";
	spellNames[FEATHER_FALL] = "Feather Fall";
	spellNames[MAGE_ARMOR] = "Mage Armor";
	spellNames[MAGIC_MISSILE] = "Magic Missile";
	spellNames[SLEEP] = "Sleep";
}


PathfinderWizard::~PathfinderWizard()
{
}

std::vector<std::string> PathfinderWizard::getClassFeatures() const
{
	std::vector<std::string> result;
	result.push_back("Arcane Bond: 1 per day");
	result.push_back(school + " School");
	if (school == "Universalist") {
		result.push_back("Hand of the Apprentice: 3 + INT per day");
	} else if (school == "Evocation") {
		result.push_back("Burning Hands: 1 per day");
		result.push_back("Force Missile: 3 + INT per day");
		result.push_back("Restricted Spells: See manual for list");
	} else if (school == "Illusion") {
		result.push_back("Blinding Ray: 3 + INT per day");
		result.push_back("Disguise Self: 1 per day");
		result.push_back("Restricted Spells: See manual for list");
	}
	return result;
}

std::vector<std::string> PathfinderWizard::getMagic() const
{
	std::vector<std::string> result;
	result.push_back("Unlimited cantrips per day");
	result.push_back("Two prepared, known 1st-level wizard spells per day");
	result.push_back("Known spells:");
	for (int i = 0; i < spellbook.size(); i++) {
		if (spellbook[i]) {
			result.push_back(spellNames[i]);
		}
	}
	return result;
}

void PathfinderWizard::learnSpell(const WIZARD_SPELLS spell)
{
	spellbook[spell] = true;
}

void PathfinderWizard::unlearnSpell(const WIZARD_SPELLS spell)
{
	spellbook[spell] = false;
}

int PathfinderWizard::knownSpellCount() const
{
	int total = 0;
	for (int i = 0; i < spellbook.size(); i++) {
		if (spellbook[i]) {
			++total;
		}
	}
	return total;
}

bool PathfinderWizard::isSpellKnown(const WIZARD_SPELLS spell) const
{
	return spellbook[spell];
}

void PathfinderWizard::setArcaneSchool(const std::string arcaneSchool)
{
	school = arcaneSchool;
}

std::string PathfinderWizard::getArcaneSchool() const
{
	return school;
}

int PathfinderWizard::getStartingMoney() const
{
	return 7000;
}
