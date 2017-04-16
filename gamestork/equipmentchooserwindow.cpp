//-----------------------------------------------------------------------------
/**
File: equipmentchooserwindow.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Implementation file for equipment chooser window
*/
//-----------------------------------------------------------------------------

#include "equipmentchooserwindow.h"

EquipmentChooserWindow::EquipmentChooserWindow(QWidget *parent)
	: QDialog(parent), availableItems()
{
	setupUi(this);
	loadItems();
	for (auto item : availableItems) {
		QString itemListing;
		switch (item->getItemType()) {
		case 0:
			itemListing = tr("(Item)   ");
			break;
		case 1:
			itemListing = tr("(Armor)  ");
			break;
		case 2:
			itemListing = tr("(Weapon) ");
			break;
		}
		int gp = item->getValue() / 100;
		int sp = (item->getValue() % 100) / 10;
		int cp = item->getValue() % 10;
		if (gp > 0) {
			itemListing += QString::number(gp) + tr("gp ");
		}
		if (sp > 0) {
			itemListing += QString::number(sp) + tr("sp ");
		}
		if (cp > 0) {
			itemListing += QString::number(cp) + tr("cp ");
		}
		itemListing += QString::fromStdString(item->getName());
		itemList->addItem(itemListing);
	}
}

EquipmentChooserWindow::~EquipmentChooserWindow()
{
}

void EquipmentChooserWindow::loadItems()
{
	XmlReader resourceReader("items.xml");
	if (!resourceReader.isXmlReady()) throw; //TODO add a proper exception here
	XmlDocument doc = resourceReader.getDocument();
	for (auto entry : doc.getNodesByElement("weapon")) {
		std::string weaponName = entry->getInnerValue();
		unsigned int weaponValue = 
			std::atoi(entry->getAttribute("value").c_str());
		int weaponRange = std::atoi(entry->getAttribute("range").c_str());
		WEAPON_CATEGORY weaponCategory = static_cast<WEAPON_CATEGORY>(
			std::atoi(entry->getAttribute("category").c_str()));
		std::string weaponDamage = entry->getAttribute("damage");
		char weaponDamageType = entry->getAttribute("damageType").size() > 0 ?
			entry->getAttribute("damageType")[0] : 'S';
		std::string weaponCritical = entry->getAttribute("critical");
		availableItems.push_back(std::make_shared<PathfinderWeapon>(
			PathfinderWeapon(weaponName, weaponValue, weaponRange, 
				weaponCategory, weaponDamage, weaponDamageType, 
				weaponCritical)));
	}
	for (auto entry : doc.getNodesByElement("armor")) {
		availableItems.push_back(std::make_shared<PathfinderArmor>(
			PathfinderArmor(
			entry->getInnerValue(),
			std::atoi(entry->getAttribute("value").c_str()),
			static_cast<ARMOR_WEIGHTCLASS>(
				std::atoi(entry->getAttribute("weightClass").c_str())),
			std::atoi(entry->getAttribute("acBonus").c_str()))));
	}
	for (auto entry : doc.getNodesByElement("item")) {
		availableItems.push_back(std::make_shared<InventoryItem>(
			InventoryItem(
			entry->getInnerValue(),
			std::atoi(entry->getAttribute("value").c_str()))));
	}
}


void EquipmentChooserWindow::itemSelected()
{
	if (itemList->currentRow() != -1) {
		emit addItem(availableItems[itemList->currentRow()]);
	}
	this->close();
}