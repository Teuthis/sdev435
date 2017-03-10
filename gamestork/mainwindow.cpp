#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
	newCharWindow(new ClassSelectWindow(this)),
	character(NULL),
	unsavedChanges(false)
{
    ui->setupUi(this);

	QObject::connect(
		newCharWindow, SIGNAL(classChosen(CHARACTER_CLASS)),
		this, SLOT(classSelected(CHARACTER_CLASS)));

	changeClassOptionsDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::classSelected(CHARACTER_CLASS chosenClass)
{
	/*delete newCharWindow;
	newCharWindow = NULL;*/
	character = new PathfinderCharacter(chosenClass);
	changeClassOptionsDisplay(chosenClass);
	unsavedChanges = true;
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
