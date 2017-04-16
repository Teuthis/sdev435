#pragma once

#include <QDialog>
#include <vector>
#include <cstdlib>
#include <memory>
#include <InventoryItem.h>
#include <PathfinderArmor.h>
#include <PathfinderWeapon.h>
#include <XmlDocument.h>
#include <XmlReader.h>
#include "ui_equipmentchooserwindow.h"

class EquipmentChooserWindow : public QDialog, public Ui::EquipmentChooserWindow
{
	/// QT required reference for slots/signals system
	Q_OBJECT

public:
	/// Constructs a new EquipmentChooserWindow object
	/// @param parent Pointer to the parent window
	EquipmentChooserWindow(QWidget *parent = Q_NULLPTR);

	/// Destroys the EquipmentChooserWindow
	~EquipmentChooserWindow();

private:
	/// The items available for purchase
	std::vector<std::shared_ptr<InventoryItem>> availableItems;

	/// Loads the items manifest from a resource file
	void loadItems();

public slots:
	/// Triggered when the ok button is clicked
	/// Emits the addItem signal with a pointer to the selected item
	void itemSelected();

signals:
	/// Sends a pointer to the selected item to all connected slots
	void addItem(std::shared_ptr<InventoryItem>);
};
