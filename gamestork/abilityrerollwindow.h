#pragma once

#include <QDialog>
#include <vector>
#include <algorithm>
#include <sstream>
#include "ui_abilityrerollwindow.h"
#include <DiceRoller.h>

class AbilityRerollWindow : public QDialog, public Ui::AbilityRerollWindow
{
	Q_OBJECT

public:
	AbilityRerollWindow(QWidget *parent = Q_NULLPTR);
	~AbilityRerollWindow();

	void setInitialValues(int initStr, int initDex, int initCon,
		int initInt, int initWis, int initCha);

public slots:
	void rerollScores();

	void changesAccepted();

	void testValidity();

signals:
	void abilitiesChanged(int, int, int, int, int, int);

private:
	DiceRoller dice;
	std::vector<int> rollTotals;
	std::vector<std::vector<int>> rollDetails;

	int getStrIndex();
	int getDexIndex();
	int getConIndex();
	int getIntIndex();
	int getWisIndex();
	int getChaIndex();

	void updateAbilityDisplay();
	void updateAbilityTooltips(int sequence, int a, int b, int c, int d, int low);
};
