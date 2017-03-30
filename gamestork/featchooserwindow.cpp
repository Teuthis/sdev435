#include "featchooserwindow.h"

FeatChooserWindow::FeatChooserWindow(QWidget *parent)
	: QDialog(parent), allFeats()
{
	setupUi(this);
	
	XmlReader resourceReader("feats.xml");
	if (!resourceReader.isXmlReady()) throw; //TODO add a proper exception here
	XmlDocument doc = resourceReader.getDocument();
	for (auto entry : doc.getNodesByElement("feat")) {
		// initialize prerequisite defaults
		int abilityPrereq = 0, attackPrereq = 0, proficiencyPrereq = 0,
			classPrereq = FIGHTER | ROGUE | CLERIC | WIZARD;
		CHARACTER_ABILITY abilityType = STRENGTH;
		for (int i = 0; i < entry->getChildCount(); i++) {
			auto prereq = entry->operator[](i);
			if (prereq->getElement() == "abilityPrereq") {
				abilityType = static_cast<CHARACTER_ABILITY>(
					std::atoi(prereq->getAttribute("ability").c_str()));
				abilityPrereq = std::atoi(prereq->getInnerValue().c_str());
			} else if (prereq->getElement() == "attackPrereq") {
				attackPrereq = std::atoi(prereq->getInnerValue().c_str());
			} else if (prereq->getElement() == "classPrereq") {
				classPrereq = std::atoi(prereq->getInnerValue().c_str());
			} else if (prereq->getElement() == "proficiency") {
				proficiencyPrereq = std::atoi(prereq->getInnerValue().c_str());
			}
		}
		allFeats.push_back(PathfinderFeat(entry->getAttribute("name"),
			abilityType, abilityPrereq, attackPrereq, proficiencyPrereq,
			classPrereq));
	}
}

FeatChooserWindow::~FeatChooserWindow()
{
}

void FeatChooserWindow::setAvailableFeats(
	const PathfinderCharacter * const character)
{
	featsList->clear();
	for (int i = 0; i < allFeats.size(); i++) {
		if (allFeats[i].meetsAbilityPrerequisite(character->getAbilityScore(
			allFeats[i].getAbilityPrerequisite()), 
			allFeats[i].getAbilityPrerequisite()) &&
			allFeats[i].meetsAttackBonusPrerequisite(
				character->getCharacterStatistic(ATTACK_BONUS)) &&
			allFeats[i].meetsClassPrerequisite(character->getClassId()) &&
			allFeats[i].meetsProficiencyPrerequisite(
				character->getProficiencies())) {
			featsList->addItem(QString::fromStdString(allFeats[i].toString()));
			featsList->item(featsList->count() - 1)->setData(Qt::UserRole, i);
		}
	}
}


void FeatChooserWindow::featChosen() 
{
	if (featsList->currentRow() != -1) {
		int feat = featsList->currentItem()->data(Qt::UserRole).toInt();
		emit featAdded(allFeats[feat]);
	}
	this->close();
}