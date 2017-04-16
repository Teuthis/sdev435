//-----------------------------------------------------------------------------
/**
File: Inventory.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Unit tests for inventory objects
*/
//-----------------------------------------------------------------------------

#include <UnitTest++.h>
#include "InventoryItem.h"
#include "PathfinderArmor.h"
#include "PathfinderWeapon.h"

SUITE(InventoryTests) {

	TEST(DefaultItem) {
		InventoryItem item;
		CHECK_EQUAL("Simple Item", item.getName());
	}

	TEST(DefaultWeaponValues) {
		PathfinderWeapon weapon;
		InventoryItem *item = &weapon;
		CHECK_EQUAL("Weapon", item->getName());
	}
}