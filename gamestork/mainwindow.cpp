#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
	newCharWindow(new ClassSelectWindow(this)),
	abilityEditor(new AbilityRerollWindow(this)),
	character(NULL),
	unsavedChanges(false)
{
    ui->setupUi(this);

	QObject::connect(
		newCharWindow, SIGNAL(classChosen(CHARACTER_CLASS)),
		this, SLOT(classSelected(CHARACTER_CLASS)));

	QObject::connect(
		abilityEditor , SIGNAL(abilitiesChanged(int, int, int, int, int, int)),
		this, SLOT(editAbilities(int, int, int, int, int, int)));

	changeClassOptionsDisplay();
}

MainWindow::~MainWindow()
{
	if (character != NULL) delete character;
	delete newCharWindow;
	delete abilityEditor;
    delete ui;
}

void MainWindow::classSelected(CHARACTER_CLASS chosenClass)
{
	/*delete newCharWindow;
	newCharWindow = NULL;*/
	character = new PathfinderCharacter(chosenClass);
	changeClassOptionsDisplay(chosenClass);
	//unsavedChanges = true;
	characterLoaded();
}

void MainWindow::editAlignment(int selectedAlignment)
{
	if (character == NULL) return;
	if (selectedAlignment != character->getAlignment()) {
		character->setAlignment(
			static_cast<ALIGNMENT>(selectedAlignment));
		unsavedChanges = true;
	}
}

void MainWindow::editName(QString newName)
{
	if (character == NULL) return;
	std::string namestr = newName.toStdString();
	if (namestr != character->getName()) {
		character->setName(namestr);
		unsavedChanges = true;
	}
}

void MainWindow::editRace(int raceIndex)
{
	if (character == NULL) return;
	if (raceIndex != -1 && raceIndex != character->getRaceId()) {
		character->setRace(static_cast<CHARACTER_RACE>(raceIndex));
		unsavedChanges = true;
		updateAbilityDisplay();
	}
}

void MainWindow::editAbilities(int str, int dex, int con, 
	int intel, int wis, int cha)
{
	if (character == NULL) return;
	character->setAbility(STRENGTH, str);
	character->setAbility(DEXTERITY, dex);
	character->setAbility(CONSTITUTION, con);
	character->setAbility(INTELLIGENCE, intel);
	character->setAbility(WISDOM, wis);
	character->setAbility(CHARISMA, cha);
	updateAbilityDisplay();
}

void MainWindow::openAbilityEditor()
{
	abilityEditor->setInitialValues(
		character->getRawAbilityScore(STRENGTH),
		character->getRawAbilityScore(DEXTERITY),
		character->getRawAbilityScore(CONSTITUTION),
		character->getRawAbilityScore(INTELLIGENCE),
		character->getRawAbilityScore(WISDOM),
		character->getRawAbilityScore(CHARISMA));
	abilityEditor->show();
}

void MainWindow::characterLoaded()
{
	if (character == NULL) {
		throw; //TODO add a proper exception
	}
	ui->nameEdit->setText(
		QString::fromStdString(character->getName()));
	ui->nameEdit->setEnabled(true);

	ui->alignSelect->setCurrentIndex(character->getAlignment());
	ui->alignSelect->setEnabled(true);

	ui->raceSelect->setCurrentIndex(character->getRaceId());
	ui->raceSelect->setEnabled(true);

	updateAbilityDisplay();
	ui->abilityEdit->setEnabled(true);

	ui->gpValLabel->setText(QString::number(character->getGoldPieces()));
	ui->spValLabel->setText(QString::number(character->getSilverPieces()));
	ui->cpValLabel->setText(QString::number(character->getCopperPieces()));
}

void MainWindow::updateAbilityDisplay()
{
	ui->strVal->setText(QString::number(
		character->getAbilityScore(STRENGTH)));
	ui->dexVal->setText(QString::number(
		character->getAbilityScore(DEXTERITY)));
	ui->conVal->setText(QString::number(
		character->getAbilityScore(CONSTITUTION)));
	ui->intVal->setText(QString::number(
		character->getAbilityScore(INTELLIGENCE)));
	ui->wisVal->setText(QString::number(
		character->getAbilityScore(WISDOM)));
	ui->chaVal->setText(QString::number(
		character->getAbilityScore(CHARISMA)));
}

void MainWindow::changeClassOptionsDisplay(int classToShow)
{
	ui->clericGroup->hide();
	ui->fighterGroup->hide();
	ui->rogueGroup->hide();
	ui->wizardGroup->hide();
	switch (classToShow) {
	case CLERIC:
		ui->clericGroup->show();
		break;
	case FIGHTER:
		ui->fighterGroup->show();
		break;
	case ROGUE:
		ui->rogueGroup->show();
		break;
	case WIZARD:
		ui->wizardGroup->show();
		break;
	}
}

bool MainWindow::promptToSaveChanges()
{
	QMessageBox prompt;
	prompt.setText("This character has been modified.");
	prompt.setInformativeText("Would you like to save changes?");
	prompt.setStandardButtons(
		QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
	prompt.setDefaultButton(QMessageBox::Save);
	int result = prompt.exec();
	switch (result) {
	case QMessageBox::Save:
		//TODO Add saving
		return true;
	case QMessageBox::Discard:
		return true;
	case QMessageBox::Cancel:
		return false;
	}
	return false;
}

void MainWindow::makeEditable(bool enabled)
{
	ui->nameEdit->setEnabled(enabled);
	ui->alignSelect->setEnabled(enabled);
	ui->raceSelect->setEnabled(enabled);
	ui->genderSelect->setEnabled(enabled);
	ui->abilityEdit->setEnabled(enabled);
}


void MainWindow::newCharacter()
{
	if (unsavedChanges && !promptToSaveChanges()) {
		return;
	}
	if (character != NULL) {
		delete character;
		character = NULL;
	}
	newCharWindow->show();
}
