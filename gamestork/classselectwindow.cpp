#include "classselectwindow.h"

ClassSelectWindow::ClassSelectWindow(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}

ClassSelectWindow::~ClassSelectWindow()
{
}

void ClassSelectWindow::clericClicked()
{
	emit classChosen(CLERIC);
	this->close();
}

void ClassSelectWindow::fighterClicked()
{
	emit classChosen(FIGHTER);
	this->close();
}

void ClassSelectWindow::rogueClicked()
{
	emit classChosen(ROGUE);
	this->close();
}

void ClassSelectWindow::wizardClicked()
{
	emit classChosen(WIZARD);
	this->close();
}