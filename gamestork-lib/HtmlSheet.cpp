#include "HtmlSheet.h"



HtmlSheet::HtmlSheet()
{
}


HtmlSheet::~HtmlSheet()
{
}

std::string HtmlSheet::generateCharacterSheet(PathfinderCharacter * pfCharacter)
{
	character = pfCharacter;
	std::string sheet = generateHtmlDocument();
	character = 0;
	return sheet;
}

std::string HtmlSheet::generateHtmlDocument() const
{
	std::string output = "<!DOCTYPE html>\n";
	output += "<html lang=\"en\">\n";
	output += generateHeader();
	output += "\t<body>\n";
	output += generateGeneralInfoTable();
	output += "\t\t<div class=\"left\">\n";
	output += generateAbilityTable();
	output += generateRacialTable();
	output += generateSkillsTable();
	output += generateProficiencyTable();
	output += "\t\t</div>\n";
	output += "\t\t<div class=\"right\">\n";
	output += generateClassFeaturesTable();
	output += generateAttackTable();
	output += generateArmorTable();
	output += generateFeatsTable();
	output += generateEquipmentTable();
	output += generateSpellsTable();
	output += "\t\t</div>\n";
	output += "\t</body>\n";
	output += "</html>";
	return output;
}

std::string HtmlSheet::generateHeader() const
{
	std::string output = "\t<head>\n";
	output += "\t\t<meta charset=\"utf-8\" />\n";
	output += "\t\t<title>Character sheet: " + character->getName() 
		+ "</title>\n";
	output += "\t\t" + CSS_STYLE + "\n\t</head>\n";
	return output;
}

std::string HtmlSheet::generateGeneralInfoTable() const
{
	std::string output = "\t\t<h1>" + character->getClassName() 
		+ " Character Sheet</h2>\n";
	output += "\t\t<div class=\"full\">\n";
	output += "\t\t\t<table>\n\t\t\t\t<tr>\n";
	output += "\t\t\t\t\t<td colspan=\"2\" class=\"inverse\">";
	output += character->getName() + "</td>\n";
	output += "\t\t\t\t\t<td colspan=\"2\"><span class=\"labeltext\">";
	output += "Race</span>" + character->getRace() + "</td>\n\t\t\t\t</tr>\n";
	output += "\t\t\t\t<tr>\n\t\t\t\t\t<td colspan=\"2\">";
	output += character->getName() + "</td>\n";
	output += "\t\t\t\t\t<td colspan=\"2\"><span class=\"labeltext\">"; 
	output += "Class</span>" + character->getClassName() + "</td>\n\t\t\t\t</tr>\n";
	output += "\t\t\t\t<tr>\n\t\t\t\t\t<td><span class=\"labeltext\">Alignment";
	output += "</span>" + alignmentString(character->getAlignment()) + "</td>\n";
	output += "\t\t\t\t\t<td><span class=\"labeltext\">Gender</span>";
	output += genderString(character->getGender()) + "</td>\n";
	output += "\t\t\t\t\t<td><span class=\"labeltext\">Experience</span>0</td>\n";
	output += "\t\t\t\t\t<td><span class=\"labeltext\">Level</span>1</td>\n";
	output += "\t\t\t\t</tr>\n\t\t\t</table>\n\t\t</div>\n";
	return output;
}

std::string HtmlSheet::generateAbilityTable() const
{
	std::string output = "\t\t\t<table>\n\t\t\t\t<tr>\n";
	output += "\t\t\t\t\t<td colspan=\"2\" class=\"inverse\">Ability Scores</td>\n";
	output += "\t\t\t\t\t<td colspan=\"2\" class=\"inverse\">Ability Modifiers</td>\n";
	output += "\t\t\t\t</tr>\n\t\t\t\t<tr>\n";
	output += "\t\t\t\t\t<td class=\"labeltext\">Strength</td>\n";
	output += "\t\t\t\t\t<td class=\"datafield\">"; 
	output += std::to_string(character->getAbilityScore(STRENGTH)) + "</td>\n";
	output += "\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getAbilityBonusMod(STRENGTH)) + "</td>\n";
	output += "\t\t\t\t\t<td class=\"labeltext\">Str Modifier</td>\n";
	output += "\t\t\t\t</tr>\n\t\t\t\t<tr>\n";
	output += "\t\t\t\t\t<td class=\"labeltext\">Dexterity</td>\n";
	output += "\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getAbilityScore(DEXTERITY)) + "</td>\n";
	output += "\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getAbilityBonusMod(DEXTERITY)) + "</td>\n";
	output += "\t\t\t\t\t<td class=\"labeltext\">Dex Modifier</td>\n";
	output += "\t\t\t\t</tr>\n\t\t\t\t<tr>\n";
	output += "\t\t\t\t\t<td class=\"labeltext\">Constitution</td>\n";
	output += "\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getAbilityScore(CONSTITUTION)) + "</td>\n";
	output += "\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getAbilityBonusMod(CONSTITUTION)) + "</td>\n";
	output += "\t\t\t\t\t<td class=\"labeltext\">Con Modifier</td>\n";
	output += "\t\t\t\t</tr>\n\t\t\t\t<tr>\n";
	output += "\t\t\t\t\t<td class=\"labeltext\">Intelligence</td>\n";
	output += "\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getAbilityScore(INTELLIGENCE)) + "</td>\n";
	output += "\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getAbilityBonusMod(INTELLIGENCE)) + "</td>\n";
	output += "\t\t\t\t\t<td class=\"labeltext\">Int Modifier</td>\n";
	output += "\t\t\t\t</tr>\n\t\t\t\t<tr>\n";
	output += "\t\t\t\t\t<td class=\"labeltext\">Wisdom</td>\n";
	output += "\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getAbilityScore(WISDOM)) + "</td>\n";
	output += "\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getAbilityBonusMod(WISDOM)) + "</td>\n";
	output += "\t\t\t\t\t<td class=\"labeltext\">Wis Modifier</td>\n";
	output += "\t\t\t\t</tr>\n\t\t\t\t<tr>\n";
	output += "\t\t\t\t\t<td class=\"labeltext\">Charisma</td>\n";
	output += "\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getAbilityScore(CHARISMA)) + "</td>\n";
	output += "\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getAbilityBonusMod(CHARISMA)) + "</td>\n";
	output += "\t\t\t\t\t<td class=\"labeltext\">Cha Modifier</td>\n";
	output += "\t\t\t\t</tr>\n\t\t\t</table>\n";
	return output;
}

std::string HtmlSheet::generateRacialTable() const
{
	std::string output = "\t\t\t<table>\n\t\t\t\t<tr>\n";
	output += "\t\t\t\t\t<td class=\"inverse\">Racial Traits</td>\n";
	output += "\t\t\t\t</tr>\n\t\t\t\t\t<td>Speed: ";
	output += std::to_string(character->getSpeed(false)) + " feet (";
	output += std::to_string(character->getSpeed(true)) + " squares)</td>\n";
	output += "\t\t\t\t</tr>\n";
	for (auto trait : character->getTraits()) {
		output += "\t\t\t\t<tr>\n\t\t\t\t\t<td>" + trait + 
			"</td>\n\t\t\t\t</tr>\n";
	}
	output += "\t\t\t</table>\n";	
	return output;
}

std::string HtmlSheet::generateSkillsTable() const
{
	std::string output = "\t\t\t<table>\n\t\t\t\t<tr>\n";
	output += "\t\t\t\t\t<td class=\"inverse\">Skills</td>\n";
	output += "\t\t\t\t\t<td class=\"inverse smallhead\">Class<br/>Skill</td>\n";
	output += "\t\t\t\t\t<td class=\"inverse smallhead\">Ranks</td>\n";
	output += "\t\t\t\t\t<td class=\"inverse smallhead\">Ability<br/>Mod</td>\n";
	output += "\t\t\t\t\t<td class=\"inverse smallhead\">Total</td>\n\t\t\t\t</tr>\n";
	for (int i = 0; i <= SWIM; i++) {
		auto skill = character->getSkill(static_cast<CHARACTER_SKILLS>(i));
		output += "\t\t\t\t<tr>\n";
		if (skill.isTrainedOnly()) {
			output += "\t\t\t\t\t<td class=\"labeltext trained\">";
		} else {
			output += "\t\t\t\t\t<td class=\"labeltext\">";
		}
		output += skill.toString() + "</td>\n";
		output += "\t\t\t\t\t<td class=\"datafield\">";
		output += (skill.isClassSkill() ? "X" : "") + std::string("</td>\n");
		output += "\t\t\t\t\t<td class=\"datafield\">";
		output += std::to_string(skill.getRanks()) + "</td>\n";
		output += "\t\t\t\t\t<td class=\"datafield\">";
		output += std::to_string(character->getAbilityBonusMod(skill.getAbility()));
		output += "</td>\n";
		output += "\t\t\t\t\t<td class=\"datafield\">";
		int total = skill.getRanks() + 
			character->getAbilityBonusMod(skill.getAbility());
		if (skill.isTrainedOnly() && skill.getRanks() == 0) {
			total = 0;
		}
		output += std::to_string(total) + "</td>\n\t\t\t\t</tr>\n";
	}
	output += "\t\t\t</table>\n";
	return output;
}

std::string HtmlSheet::generateProficiencyTable() const
{
	std::string output = "\t\t\t<table>\n\t\t\t\t<tr>\n";
	output += "\t\t\t\t\t<td class=\"inverse\">Armor and Weapon Proficiencies";
	output += "</td>\n\t\t\t\t</tr>\n";
	int prof = character->getProficiencies();
	if ((prof & SIMPLE_WEAPONS) > 0) {
		output += "\t\t\t\t<tr>\n";
		output += "\t\t\t\t\t<td>Simple Weapons</td>\n";
		output += "\t\t\t\t</tr>\n";
	}
	if ((prof & MARTIAL_WEAPONS) > 0) {
		output += "\t\t\t\t<tr>\n";
		output += "\t\t\t\t\t<td>Martial Weapons</td>\n";
		output += "\t\t\t\t</tr>\n";
	}
	if ((prof & LIGHT_ARMOR) > 0) {
		output += "\t\t\t\t<tr>\n";
		output += "\t\t\t\t\t<td>Light Armor</td>\n";
		output += "\t\t\t\t</tr>\n";
	}
	if ((prof & MEDIUM_ARMOR) > 0) {
		output += "\t\t\t\t<tr>\n";
		output += "\t\t\t\t\t<td>Medium Armor</td>\n";
		output += "\t\t\t\t</tr>\n";
	}
	if ((prof & HEAVY_ARMOR) > 0) {
		output += "\t\t\t\t<tr>\n";
		output += "\t\t\t\t\t<td>Heavy Armor</td>\n";
		output += "\t\t\t\t</tr>\n";
	}
	if ((prof & SHIELDS) > 0) {
		output += "\t\t\t\t<tr>\n";
		output += "\t\t\t\t\t<td>Shields</td>\n";
		output += "\t\t\t\t</tr>\n";
	}
	output += "\t\t\t</table>\n";
	return output;
}

std::string HtmlSheet::generateClassFeaturesTable() const
{
	std::string output = "\t\t\t<table>\n\t\t\t\t<tr>\n";
	output += "\t\t\t\t\t<td class=\"inverse\">Class Features</td>\n";
	output += "\t\t\t\t\t<td colspan=\"3\"><span class=\"labeltext\">Hit Points</span>";
	output += std::to_string(character->getHitpoints()) + "</td>\n\t\t\t\t</tr>\n";
	output += "\t\t\t\t<tr>\n\t\t\t\t\t<td class=\"attackhead\"></td>\n";
	output += "\t\t\t\t\t<td class=\"smallhead\">Class</td>\n";
	output += "\t\t\t\t\t<td class=\"smallhead\">Ability</td>\n";
	output += "\t\t\t\t\t<td class=\"smallhead\">Total</td>\n\t\t\t\t</tr>";
	int fort = character->getCharacterStatistic(FORTITUDE_SAVE);
	int fortMod = character->getAbilityBonusMod(CONSTITUTION);
	output += "\t\t\t\t<tr>\t\t\t\t\t<td class=\"labeltext\">Fortitude Save</td>\n";
	output += "\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(fort);
	output += "</td>\n\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(fortMod);
	output += "</td>\n\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(fort + fortMod) + "</td>\n\t\t\t\t</tr>\n";
	int rflx = character->getCharacterStatistic(REFLEX_SAVE);
	int rflxMod = character->getAbilityBonusMod(DEXTERITY);
	output += "\t\t\t\t<tr>\t\t\t\t\t<td class=\"labeltext\">Reflex Save</td>\n";
	output += "\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(rflx);
	output += "</td>\n\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(rflxMod);
	output += "</td>\n\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(rflx + rflxMod) + "</td>\n\t\t\t\t</tr>\n";
	int will = character->getCharacterStatistic(WILL_SAVE);
	int willMod = character->getAbilityBonusMod(WISDOM);
	output += "\t\t\t\t<tr>\t\t\t\t\t<td class=\"labeltext\">Will Save</td>\n";
	output += "\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(will);
	output += "</td>\n\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(willMod);
	output += "</td>\n\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(will + willMod) + "</td>\n\t\t\t\t</tr>\n";
	output += "\t\t\t\t<tr>\t\t\t\t\t<td class=\"labeltext\">Attack Bonus</td>\n";
	output += "\t\t\t\t\t<td></td>\n\t\t\t\t\t<td></td>\n";
	output += "\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getCharacterStatistic(ATTACK_BONUS));
	output += "</td>\n\t\t\t\t</tr>\n";
	for (auto feature : character->getClassFeatures()) {
		output += "\t\t\t\t<tr>\n\t\t\t\t\t<td colspan=\"4\">";
		output += feature + "</td>\n\t\t\t\t</tr>\n";
	}
	output += "\t\t\t</table>\n";
	return output;
}

std::string HtmlSheet::generateAttackTable() const
{
	std::string output = "\t\t\t<table>\n\t\t\t\t<tr>\n";
	output += "\t\t\t\t\t<td colspan=\"6\" class=\"inverse\">";
	output += "Weapons and Attacks</td>\n\t\t\t\t</tr>\n";
	output += "\t\t\t\t<tr>\n\t\t\t\t\t<td colspan=\"3\" class=\"labeltext\">";
	output += "Initiative</td>\n\t\t\t\t\t<td class=\"datafield\"></td>\n";
	output += "\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getAbilityBonusMod(DEXTERITY));
	output += "</td>\n\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getAbilityBonusMod(DEXTERITY));
	output += "</td>\n\t\t\t\t</tr>\n";
	output += "\t\t\t\t<tr>\n\t\t\t\t\t<td colspan=\"3\" class=\"labeltext\">";
	output += "Melee Attack</td>\n\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getCharacterStatistic(ATTACK_BONUS));
	output += "</td>\n\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getAbilityBonusMod(STRENGTH));
	output += "</td>\n\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getCharacterStatistic(ATTACK_BONUS)
		+ character->getAbilityBonusMod(STRENGTH));
	output += "</td>\n\t\t\t\t</tr>\n";
	output += "\t\t\t\t<tr>\n\t\t\t\t\t<td colspan=\"3\" class=\"labeltext\">";
	output += "Ranged Attack</td>\n\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getCharacterStatistic(ATTACK_BONUS));
	output += "</td>\n\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getAbilityBonusMod(DEXTERITY));
	output += "</td>\n\t\t\t\t\t<td class=\"datafield\">";
	output += std::to_string(character->getCharacterStatistic(ATTACK_BONUS)
		+ character->getAbilityBonusMod(DEXTERITY));
	output += "</td>\n\t\t\t\t</tr>\n";

	for (auto weapon : character->getWeapons()) {
		output += "\t\t\t\t<tr>\n\t\t\t\t\t<td colspan=\"2\" class=\"inverse\">";
		output += "Weapon</td>\n\t\t\t\t\t<td colspan=\"4\">";
		output += weapon.getName() + "</td>\n\t\t\t\t</tr>\n\t\t\t\t<tr>\n";
		output += "\t\t\t\t\t<td class=\"attackhead\">Attack Bonus</td>\n";
		output += "\t\t\t\t\t<td class=\"attackhead\">Damage</td>\n";
		output += "\t\t\t\t\t<td class=\"attackhead\">Critical Threat</td>\n";
		output += "\t\t\t\t\t<td class=\"attackhead\">Damage Type</td>\n";
		output += "\t\t\t\t\t<td class=\"attackhead\">Range Increment</td>\n";
		output += "\t\t\t\t\t<td class=\"attackhead\">Ammunition</td>\n";
		output += "\t\t\t\t</tr>\n\t\t\t\t<tr>\n";
		output += "\t\t\t\t\t<td class=\"datafield\"></td>\n";
		output += "\t\t\t\t\t<td class=\"datafield\">";
		output += weapon.getDamage() + "</td>\n";
		output += "\t\t\t\t\t<td class=\"datafield\"></td>\n";
		output += "\t\t\t\t\t<td class=\"datafield\"></td>\n";
		output += "\t\t\t\t\t<td class=\"datafield\">";
		output += std::to_string(weapon.getRange()) + "</td>\n";
		output += "\t\t\t\t\t<td class=\"datafield\"></td>\n\t\t\t\t</tr>\n";
	}

	output += "\t\t\t</table>\n";
	return output;
}

std::string HtmlSheet::generateArmorTable() const
{
	return std::string();
}

std::string HtmlSheet::generateFeatsTable() const
{
	std::string output = "\t\t\t<table>\n\t\t\t\t<tr>\n";
	output += "\t\t\t\t\t<td class=\"inverse\">Feats</td>\n\t\t\t\t</tr>\n";
	for (auto feat : character->getFeats()) {
		output += "\t\t\t\t<tr>\n\t\t\t\t\t<td class=\"datafield\">";
		output += feat.toString() + "</td>\n\t\t\t\t</tr>\n";
	}
	output += "\t\t\t</table>\n";
	return output;
}

std::string HtmlSheet::generateEquipmentTable() const
{
	std::string output = "\t\t\t<table>\n\t\t\t\t<tr>\n";
	output += "\t\t\t\t\t<td colspan=\"2\" class=\"inverse\">Equipment";
	output += "</td>\n\t\t\t\t</tr>\n";
	auto items = character->getInventory();
	size_t rows = (items.size() / 2) + (items.size() % 2);
	for (int i = 0; i < rows; i++) {
		output += "\t\t\t\t<tr>\n\t\t\t\t\t<td>";
		output += items[i * 2]->getName();
		output += "</td>\n\t\t\t\t\t<td>";
		if ((i * 2) + 1 < items.size()) {
			output += items[(i * 2) + 1]->getName();
		}
		output += "</td>\n\t\t\t\t</tr>\n";
	}
	output += "\t\t\t</table>\n";
	return output;
}

std::string HtmlSheet::generateSpellsTable() const
{
	std::string output = "\t\t\t<table>\n\t\t\t\t<tr>\n";
	output += "\t\t\t\t\t<td class=\"inverse\">Spells</td>\n";
	output += "\t\t\t\t</tr>\n";
	for (auto spell : character->getSpells()) {
		output += "\t\t\t\t<tr>\n\t\t\t\t\t<td>";
		output += spell + "</td>\n\t\t\t\t</tr>\n";
	}
	output += "\t\t\t</table>\n";
	return output;
}

std::string HtmlSheet::alignmentString(const ALIGNMENT alignment) const
{
	switch (alignment) {
	case LAWFUL_GOOD:
		return "Lawful Good";
	case LAWFUL_NEUTRAL:
		return "Lawful Neutral";
	case LAWFUL_EVIL:
		return "Lawful Evil";
	case NEUTRAL_GOOD:
		return "Neutral Good";
	case TRUE_NEUTRAL:
		return "Neutral";
	case NEUTRAL_EVIL:
		return "Neutral Evil";
	case CHAOTIC_GOOD:
		return "Chaotic Good";
	case CHAOTIC_NEUTRAL:
		return "Chaotic Neutral";
	case CHAOTIC_EVIL:
		return "Chaotic Evil";
	default:
		return "";
	}
}

std::string HtmlSheet::genderString(const GENDER gender) const
{
	switch (gender) {
	case MALE:
		return "Male";
	case FEMALE:
		return "Female";
	case OTHER:
		return "Other";
	case NOGENDER:
		return "None";
	default:
		return std::string();
	}
}

