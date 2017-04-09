#pragma once

#include <string>
#include "PathfinderCharacter.h"

class HtmlSheet
{
public:
	HtmlSheet();
	~HtmlSheet();

	std::string generateCharacterSheet(PathfinderCharacter* pfCharacter);

private:
	/// Pointer to the character this sheet is for
	PathfinderCharacter* character;

	/// Generates the HTML document structure
	/// @return An HTML representation of the character sheet
	std::string generateHtmlDocument() const;

	/// Generates the document heading
	/// @return HTML markup for the <head> section of the document
	std::string generateHeader() const;

	/// Generates the full width table at the top of the page
	/// @return HTML markup for the top table
	std::string generateGeneralInfoTable() const;

	/// Generates the ability table
	/// @return HTML markup for the ability table
	std::string generateAbilityTable() const;

	/// Generates the racial traits table
	/// @return HTML markup for the racial traits table
	std::string generateRacialTable() const;

	/// Generates the skills table
	/// @return HTML markup for the skills table
	std::string generateSkillsTable() const;

	/// Generates the proficiency table
	/// @return HTML markup for the skills table
	std::string generateProficiencyTable() const;

	/// Generates the class features table
	/// @return HTML markup for the class features table
	std::string generateClassFeaturesTable() const;

	/// Generates the attack table
	/// @return HTML markup for the attack table
	std::string generateAttackTable() const;

	/// Generates the armor table
	/// @return HTML makrup for the armor table
	std::string generateArmorTable() const;

	/// Generates the feats table
	/// @return HTML markup for the feats table
	std::string generateFeatsTable() const;

	/// Generates the equipment table
	/// @return HTML markup for the equipment table
	std::string generateEquipmentTable() const;

	/// Generates the spells table
	/// @return HTML markup for the spells table
	std::string generateSpellsTable() const;

	/// Converts alignment enum to string
	/// @param alignment Integer alignment value
	/// @return string version of the alignment
	std::string alignmentString(const ALIGNMENT alignment) const;

	/// Converts gender enum to string
	/// @param alignment Integer gender value
	/// @return string version of the gender
	std::string genderString(const GENDER gender) const;

	/// The CSS definition for the character sheet
	const std::string CSS_STYLE = "<style>body{box-sizing:border-box;height:11in;margin:0 auto;overflow:hidden;padding:0.5in;width:8.5in;font-family:sans-serif;} table{width:100%;padding-top:10px;padding-bottom:10px;margin-top:10px;margin-bottom:10px;} table,td{border:1px solid black;border-collapse:collapse;} div.full{width:100%;} div.left{width:49%;padding-right:5px;float:left;} div.right{width:49%;padding-left:5px;float:right;} td.inverse{background-color:maroon;color:white;text-transform:uppercase;font-weight:bold;} td.attackhead{background-color:black;color:white;text-transform:uppercase;font-weight:bold;font-size:xx-small;text-align:center;} td.datafield{text-align:center;padding-left:5px;padding-right:5px;} .labeltext{font-weight:bold;font-size:70%;padding-right:10px;text-transform:uppercase;} .smallhead{font-size:xx-small;text-align:center;} .trained{color:gray;}</style>";
};

