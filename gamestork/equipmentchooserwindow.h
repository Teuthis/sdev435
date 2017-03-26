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
	Q_OBJECT

public:
	EquipmentChooserWindow(QWidget *parent = Q_NULLPTR);
	~EquipmentChooserWindow();

private:
	std::vector<std::shared_ptr<InventoryItem>> availableItems;

	void loadItems();

public slots:
	void itemSelected();

signals:
	void addItem(std::shared_ptr<InventoryItem>);
};
