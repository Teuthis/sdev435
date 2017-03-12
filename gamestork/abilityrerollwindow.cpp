#include "abilityrerollwindow.h"

AbilityRerollWindow::AbilityRerollWindow(QWidget *parent)
	: QDialog(parent), dice(), rollTotals(), rollDetails()
{
	setupUi(this);
	
}

AbilityRerollWindow::~AbilityRerollWindow()
{
}

void AbilityRerollWindow::setInitialValues(int initStr, int initDex, int initCon, int initInt, int initWis, int initCha)
{
	rollTotals.clear();
	rollTotals.push_back(initStr);
	rollTotals.push_back(initDex);
	rollTotals.push_back(initCon);
	rollTotals.push_back(initInt);
	rollTotals.push_back(initWis);
	rollTotals.push_back(initCha);
	resetSelections();
	updateAbilityDisplay();
}

void AbilityRerollWindow::rerollScores() {
	rollTotals.clear();
	rollDetails.clear();
	for (int i = 0; i < 6; i++) {
		rollDetails.push_back(dice.getRollValues(4, D6));
		int lowRoll = std::min(rollDetails[i][0], rollDetails[i][1]);
		lowRoll = std::min(lowRoll, rollDetails[i][2]);
		lowRoll = std::min(lowRoll, rollDetails[i][3]);
		rollTotals.push_back(rollDetails[i][0] + rollDetails[i][1] + 
			rollDetails[i][2] + rollDetails[i][3] - lowRoll);
		updateAbilityTooltips(i, rollDetails[i][0], rollDetails[i][1],
			rollDetails[i][2], rollDetails[i][3],lowRoll);
	}
	updateAbilityDisplay();
}

void AbilityRerollWindow::changesAccepted()
{
	emit abilitiesChanged(
		rollTotals[getStrIndex()],
		rollTotals[getDexIndex()],
		rollTotals[getConIndex()],
		rollTotals[getIntIndex()],
		rollTotals[getWisIndex()],
		rollTotals[getChaIndex()]);
	this->close();
}

void AbilityRerollWindow::testValidity()
{
	int strChecked = 0, dexChecked = 0, conChecked = 0,
		intChecked = 0, wisChecked = 0, chaChecked = 0;
	
	if (roll1Str->isChecked()) strChecked++;
	if (roll2Str->isChecked()) strChecked++;
	if (roll3Str->isChecked()) strChecked++;
	if (roll4Str->isChecked()) strChecked++;
	if (roll5Str->isChecked()) strChecked++;
	if (roll6Str->isChecked()) strChecked++;

	if (roll1Dex->isChecked()) dexChecked++;
	if (roll2Dex->isChecked()) dexChecked++;
	if (roll3Dex->isChecked()) dexChecked++;
	if (roll4Dex->isChecked()) dexChecked++;
	if (roll5Dex->isChecked()) dexChecked++;
	if (roll6Dex->isChecked()) dexChecked++;

	if (roll1Con->isChecked()) conChecked++;
	if (roll2Con->isChecked()) conChecked++;
	if (roll3Con->isChecked()) conChecked++;
	if (roll4Con->isChecked()) conChecked++;
	if (roll5Con->isChecked()) conChecked++;
	if (roll6Con->isChecked()) conChecked++;

	if (roll1Int->isChecked()) intChecked++;
	if (roll2Int->isChecked()) intChecked++; 
	if (roll3Int->isChecked()) intChecked++;
	if (roll4Int->isChecked()) intChecked++;
	if (roll5Int->isChecked()) intChecked++;
	if (roll6Int->isChecked()) intChecked++;

	if (roll1Wis->isChecked()) wisChecked++;
	if (roll2Wis->isChecked()) wisChecked++;
	if (roll3Wis->isChecked()) wisChecked++;
	if (roll4Wis->isChecked()) wisChecked++;
	if (roll5Wis->isChecked()) wisChecked++;
	if (roll6Wis->isChecked()) wisChecked++;

	if (roll1Cha->isChecked()) chaChecked++;
	if (roll2Cha->isChecked()) chaChecked++;
	if (roll3Cha->isChecked()) chaChecked++;
	if (roll4Cha->isChecked()) chaChecked++;
	if (roll5Cha->isChecked()) chaChecked++;
	if (roll6Cha->isChecked()) chaChecked++;

	if (strChecked == 1 && dexChecked == 1 && conChecked == 1 &&
		intChecked == 1 && wisChecked == 1 && chaChecked == 1) {
		okButton->setEnabled(true);
	} else {
		okButton->setEnabled(false);
	}
}

int AbilityRerollWindow::getStrIndex()
{
	if (roll1Str->isChecked()) return 0;
	if (roll2Str->isChecked()) return 1;
	if (roll3Str->isChecked()) return 2;
	if (roll4Str->isChecked()) return 3;
	if (roll5Str->isChecked()) return 4;
	if (roll6Str->isChecked()) return 5;
	return -1;
}

int AbilityRerollWindow::getDexIndex()
{
	if (roll1Dex->isChecked()) return 0;
	if (roll2Dex->isChecked()) return 1;
	if (roll3Dex->isChecked()) return 2;
	if (roll4Dex->isChecked()) return 3;
	if (roll5Dex->isChecked()) return 4;
	if (roll6Dex->isChecked()) return 5;
	return -1;
}

int AbilityRerollWindow::getConIndex()
{
	if (roll1Con->isChecked()) return 0;
	if (roll2Con->isChecked()) return 1;
	if (roll3Con->isChecked()) return 2;
	if (roll4Con->isChecked()) return 3;
	if (roll5Con->isChecked()) return 4;
	if (roll6Con->isChecked()) return 5;
	return -1;
}

int AbilityRerollWindow::getIntIndex()
{
	if (roll1Int->isChecked()) return 0;
	if (roll2Int->isChecked()) return 1;
	if (roll3Int->isChecked()) return 2;
	if (roll4Int->isChecked()) return 3;
	if (roll5Int->isChecked()) return 4;
	if (roll6Int->isChecked()) return 5;
	return -1;
}

int AbilityRerollWindow::getWisIndex()
{
	if (roll1Wis->isChecked()) return 0;
	if (roll2Wis->isChecked()) return 1;
	if (roll3Wis->isChecked()) return 2;
	if (roll4Wis->isChecked()) return 3;
	if (roll5Wis->isChecked()) return 4;
	if (roll6Wis->isChecked()) return 5;
	return -1;
}

int AbilityRerollWindow::getChaIndex()
{
	if (roll1Cha->isChecked()) return 0;
	if (roll2Cha->isChecked()) return 1;
	if (roll3Cha->isChecked()) return 2;
	if (roll4Cha->isChecked()) return 3;
	if (roll5Cha->isChecked()) return 4;
	if (roll6Cha->isChecked()) return 5;
	return -1;
}

void AbilityRerollWindow::updateAbilityDisplay()
{
	roll1Label->setText(QString::number(rollTotals[0]));
	roll2Label->setText(QString::number(rollTotals[1]));
	roll3Label->setText(QString::number(rollTotals[2]));
	roll4Label->setText(QString::number(rollTotals[3]));
	roll5Label->setText(QString::number(rollTotals[4]));
	roll6Label->setText(QString::number(rollTotals[5]));
}

void AbilityRerollWindow::resetSelections()
{
	roll1Str->setChecked(true);
	roll2Dex->setChecked(true);
	roll3Con->setChecked(true);
	roll4Int->setChecked(true);
	roll5Wis->setChecked(true);
	roll6Cha->setChecked(true);
}

void AbilityRerollWindow::updateAbilityTooltips(int sequence, int a, int b, int c, int d, int low)
{
	std::stringstream tip;
	tip << "Rolled: " << a << ", " << b << ", " << c << ", " << d
		<< ", discarded " << low << ".";
	QString qtip = QString::fromStdString(tip.str());
	switch (sequence) {
	case 0:
		roll1Label->setToolTip(qtip);
		break;
	case 1:
		roll2Label->setToolTip(qtip);
		break;
	case 2:
		roll3Label->setToolTip(qtip);
		break;
	case 3:
		roll4Label->setToolTip(qtip);
		break;
	case 4:
		roll5Label->setToolTip(qtip);
		break;
	case 5:
		roll6Label->setToolTip(qtip);
		break;
	}
}

