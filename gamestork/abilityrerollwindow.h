#pragma once

#include <QDialog>
#include <vector>
#include <algorithm>
#include <sstream>
#include "ui_abilityrerollwindow.h"
#include <DiceRoller.h>

class AbilityRerollWindow : public QDialog, public Ui::AbilityRerollWindow
{
	/// QT required reference for slots/signals system
	Q_OBJECT

public:
	/// Constructs a new AbilityRerollWindow object
	/// @param parent Pointer to the parent window
	AbilityRerollWindow(QWidget *parent = Q_NULLPTR);

	/// Destroys the AbilityRerollWindow object
	~AbilityRerollWindow();

	/// Sets the starting values of the abilities to the provided
	/// @param initStr The starting strength
	/// @param initDex The starting dexterity
	/// @param initCon The starting constitution
	/// @param initInt The starting intelligence
	/// @param initWis The starting wisdom
	/// @param initCha The starting charisma
	void setInitialValues(int initStr, int initDex, int initCon,
		int initInt, int initWis, int initCha);

public slots:
	/// Triggered when the reroll button is clicked
	/// Generates new random values for the abilities
	void rerollScores();

	/// Triggered when the OK button is clicked
	/// Updates the character's abilities with the new values
	void changesAccepted();

	/// Triggered by any change to the ability grid
	/// Enables or disables the ok button based on the validity 
	/// of the ability grid. 
	void testValidity();

signals:
	/// Sends the new ability values to all connected slots
	void abilitiesChanged(int, int, int, int, int, int);

private:
	/// The dice for randomly generating the abilities
	DiceRoller dice;

	/// The drop-lowest sum of all six ability rolls
	std::vector<int> rollTotals;

	/// The individual dice values for each ability roll
	std::vector<std::vector<int>> rollDetails;

	/// Gets the roll index for the strength ability
	/// @return The index of the selected roll
	int getStrIndex();

	/// Gets the roll index for the dexterity ability
	/// @return The index of the selected roll
	int getDexIndex();

	/// Gets the roll index for the constitution ability
	/// @return The index of the selected roll
	int getConIndex();

	/// Gets the roll index for the intelligence ability
	/// @return The index of the selected roll
	int getIntIndex();

	/// Gets the roll index for the wisdom ability
	/// @return The index of the selected roll
	int getWisIndex();

	/// Gets the roll index for the charisma ability
	/// @return The index of the selected roll
	int getChaIndex();

	/// Updates the displayed values based on the current ability rolls
	void updateAbilityDisplay();

	/// Sets the ability grid to its original layout
	void resetSelections();

	/// Updates the ability tooltips based on current roll values
	/// @param sequence The roll display index
	/// @param a The first die value
	/// @param b The second die value
	/// @param c The third die value
	/// @param d The fourth die value
	/// @param low The lowest of the four rolls
	void updateAbilityTooltips(int sequence, int a, int b, int c, int d, int low);
};
