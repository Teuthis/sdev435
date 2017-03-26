#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
	newCharWindow(new ClassSelectWindow(this)),
	abilityEditor(new AbilityRerollWindow(this)),
	addSkillWindow(new AddSkillWindow(this)),
	featChooser(new FeatChooserWindow(this)),
	equipmentChooser(new EquipmentChooserWindow(this)),
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

	QObject::connect(
		addSkillWindow, SIGNAL(skillAdded(QListWidgetItem)),
		this, SLOT(addSkill(QListWidgetItem)));

	QObject::connect(
		featChooser, SIGNAL(featAdded(QListWidgetItem)),
		this, SLOT(addFeat(QListWidgetItem)));

	QObject::connect(
		equipmentChooser, SIGNAL(addItem(std::shared_ptr<InventoryItem>)),
		this, SLOT(addItem(std::shared_ptr<InventoryItem>)));

	changeClassOptionsDisplay();
}

MainWindow::~MainWindow()
{
	if (character != NULL) delete character;
	delete newCharWindow;
	delete abilityEditor;
	delete addSkillWindow;
	delete equipmentChooser;
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
		if (raceIndex == HUMAN) {
			character->changeHumanBonus(
				static_cast<CHARACTER_ABILITY>(setHumanBonusAbility()));
		}
		unsavedChanges = true;
		updateAbilityDisplay();
		updateFeatsDisplay();
		updateSkillsDisplay();
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
	updateSkillsDisplay();
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

void MainWindow::openSkillChooser()
{
	auto untrained = character->getUntrainedSkills();
	for (auto skill : untrained) {
		addSkillWindow->addSkillOption(QString::fromStdString(skill.toString()),
			skill.toSkillID());
	}
	addSkillWindow->open();
}

void MainWindow::addSkill(QListWidgetItem skill)
{
	CHARACTER_SKILLS id = static_cast<CHARACTER_SKILLS>(
		skill.data(Qt::UserRole).toInt());
	character->trainSkill(id);
	ui->skillsList->addItem(new QListWidgetItem(skill));
	updateSkillsDisplay();
}

void MainWindow::removeSkill()
{
	if (ui->skillsList->currentRow() == -1) return;

	auto skill = ui->skillsList->takeItem(ui->skillsList->currentRow());

	CHARACTER_SKILLS id = static_cast<CHARACTER_SKILLS>(
		skill->data(Qt::UserRole).toInt());
	character->untrainSkill(id);
	updateSkillsDisplay();
}

void MainWindow::skillIndexChanged(int index)
{
	if (ui->skillsList->currentRow() >= 0) {
		ui->skillsRemove->setEnabled(true);
	} else {
		ui->skillsRemove->setEnabled(false);
	}
}

void MainWindow::openEquipmentChooser()
{
	equipmentChooser->open();
}

void MainWindow::addItem(std::shared_ptr<InventoryItem> item)
{
	if (character->buyItem(item)) {
		ui->equipList->addItem(QString::fromStdString(item->getName()));
		ui->gpValLabel->setText(QString::number(character->getGoldPieces()));
		ui->spValLabel->setText(QString::number(character->getSilverPieces()));
		ui->cpValLabel->setText(QString::number(character->getCopperPieces()));
	}
}

void MainWindow::removeItem()
{
	int index = ui->equipList->currentRow();
	if (index == -1) return;
	if (character->removeItem(index)) {
		auto temp = ui->equipList->takeItem(index);
		delete temp;
		temp = 0;
		ui->gpValLabel->setText(QString::number(character->getGoldPieces()));
		ui->spValLabel->setText(QString::number(character->getSilverPieces()));
		ui->cpValLabel->setText(QString::number(character->getCopperPieces()));
	}
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

	updateFeatsDisplay();
	updateSkillsDisplay();

	ui->gpValLabel->setText(QString::number(character->getGoldPieces()));
	ui->spValLabel->setText(QString::number(character->getSilverPieces()));
	ui->cpValLabel->setText(QString::number(character->getCopperPieces()));
	ui->equipAdd->setEnabled(true);
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

int MainWindow::setHumanBonusAbility()
{
	QStringList abilities;
	abilities << tr("Strength") << tr("Dexterity") << tr("Constitution")
		<< tr("Intelligence") << tr("Wisdom") << tr("Charisma");
	bool ok;
	QString choice = QInputDialog::getItem(this, 
		tr("Select human ability bonus"), tr("Ability:"), abilities, 
		0, false, &ok);

	if (choice == tr("Strength")) return STRENGTH;
	if (choice == tr("Dexterity")) return DEXTERITY;
	if (choice == tr("Constitution")) return CONSTITUTION;
	if (choice == tr("Intelligence")) return INTELLIGENCE;
	if (choice == tr("Wisdom")) return WISDOM;
	if (choice == tr("Charisma")) return CHARISMA;
	return INTELLIGENCE;
}

void MainWindow::updateFeatsDisplay()
{
	ui->unspentFeatsCountLabel->setText(QString::number(
		character->getRemainingFeatCount()));
	if (character->getRemainingFeatCount() > 0) {
		ui->featsAdd->setEnabled(true);
	} else {
		ui->featsAdd->setEnabled(false);
	}
}

void MainWindow::updateSkillsDisplay()
{
	ui->unspentSkillsCountLabel->setText(QString::number(
		character->getRemainingSkillRanks()));
	if (character->getRemainingSkillRanks() > 0) {
		ui->skillsAdd->setEnabled(true);
	} else {
		ui->skillsAdd->setEnabled(false);
	}
}

void MainWindow::itemIndexChanged(int index)
{
	if (ui->equipList->currentRow() != -1) {
		ui->equipRemove->setEnabled(true);
	} else {
		ui->equipRemove->setEnabled(false);
	}
}

void MainWindow::openFeatChooser()
{
	featChooser->open();
}

void MainWindow::addFeat(QListWidgetItem feat)
{
	//TODO Implement addFeat()
	throw "Not yet implemented";
}

void MainWindow::removeFeat()
{
	//TODO Implement removeFeat()
	throw "Not yet implemented";
}

void MainWindow::featIndexChanged(int index)
{
	if (index == -1) {
		ui->featsRemove->setEnabled(false);
	} else {
		ui->featsRemove->setEnabled(true);
	}
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
