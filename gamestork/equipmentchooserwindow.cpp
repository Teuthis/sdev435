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
		availableItems.push_back(std::make_shared<PathfinderWeapon>(
			PathfinderWeapon(
			entry->getInnerValue(),
			std::atoi(entry->getAttribute("value").c_str()),
			0, std::atoi(entry->getAttribute("range").c_str()),
			"", entry->getAttribute("damage"))));
	}
	for (auto entry : doc.getNodesByElement("armor")) {
		availableItems.push_back(std::make_shared<PathfinderArmor>(
			PathfinderArmor(
			entry->getInnerValue(),
			std::atoi(entry->getAttribute("value").c_str()),
			0, entry->getAttribute("weightClass"),
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