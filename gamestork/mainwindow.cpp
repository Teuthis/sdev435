//-----------------------------------------------------------------------------
/**
File: mainwindow.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Implementation file for main application window
*/
//-----------------------------------------------------------------------------

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
	welcomeWindow(new WelcomeWindow(this)),
	newCharWindow(new ClassSelectWindow(this)),
	abilityEditor(new AbilityRerollWindow(this)),
	addSkillWindow(new AddSkillWindow(this)),
	featChooser(new FeatChooserWindow(this)),
	equipmentChooser(new EquipmentChooserWindow(this)),
	character(NULL),
	unsavedChanges(false)
{
    ui->setupUi(this);

	// Initialize the wizard spell list
	for (int i = 0; i < ui->spellbookList->count(); i++) {
		ui->spellbookList->item(i)->setData(Qt::UserRole, i);
	}

	// Connect class selection system
	QObject::connect(
		newCharWindow, SIGNAL(classChosen(CHARACTER_CLASS)),
		this, SLOT(classSelected(CHARACTER_CLASS)));

	// Connect ability editing system
	QObject::connect(
		abilityEditor , SIGNAL(abilitiesChanged(int, int, int, int, int, int)),
		this, SLOT(editAbilities(int, int, int, int, int, int)));

	// Connect skill editing system
	QObject::connect(
		addSkillWindow, SIGNAL(skillAdded(QListWidgetItem)),
		this, SLOT(addSkill(QListWidgetItem)));

	// Connect feat editing system
	QObject::connect(
		featChooser, SIGNAL(featAdded(PathfinderFeat)),
		this, SLOT(addFeat(PathfinderFeat)));

	// Connect equipment editing system
	QObject::connect(
		equipmentChooser, SIGNAL(addItem(std::shared_ptr<InventoryItem>)),
		this, SLOT(addItem(std::shared_ptr<InventoryItem>)));

	// Connect welcome window signals
	QObject::connect(
		welcomeWindow, SIGNAL(newChar()), this, SLOT(newCharacter()));
	QObject::connect(
		welcomeWindow, SIGNAL(openChar()), this, SLOT(open()));
	QObject::connect(
		welcomeWindow, SIGNAL(quitGamestork()), this, SLOT(close()));

	// Set the class-specific settings visibility to default
	changeClassOptionsDisplay();

	welcomeWindow->show();
}

MainWindow::~MainWindow()
{
	if (character != NULL) delete character;
	delete welcomeWindow;
	welcomeWindow = 0;
	delete newCharWindow;
	newCharWindow = 0;
	delete abilityEditor;
	abilityEditor = 0;
	delete addSkillWindow;
	addSkillWindow = 0;
	delete featChooser;
	featChooser = 0;
	delete equipmentChooser;
	equipmentChooser = 0;
    delete ui;
	ui = 0;
}

void MainWindow::closeEvent(QCloseEvent * event)
{
	if (unsavedChanges && !promptToSaveChanges()) {
		return;
	}
}

void MainWindow::classSelected(CHARACTER_CLASS chosenClass)
{
	/*delete newCharWindow;
	newCharWindow = NULL;*/
	character = new PathfinderCharacter(chosenClass);
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
		updateFeatsControls();
		updateSkillsControls();
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
	unsavedChanges = true;
	updateAbilityDisplay();
	updateSkillsControls();
	updateSpellbook();
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
	unsavedChanges = true;
	updateSkillsControls();
}

void MainWindow::removeSkill()
{
	if (ui->skillsList->currentRow() == -1) return;

	auto skill = ui->skillsList->takeItem(ui->skillsList->currentRow());

	CHARACTER_SKILLS id = static_cast<CHARACTER_SKILLS>(
		skill->data(Qt::UserRole).toInt());
	character->untrainSkill(id);
	unsavedChanges = true;
	updateSkillsControls();
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
		unsavedChanges = true;
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
		unsavedChanges = true;
	}
}

void MainWindow::characterLoaded()
{
	if (character == NULL) {
		throw; //TODO add a proper exception
	}
	
	loading = true;

	ui->nameEdit->setText(
		QString::fromStdString(character->getName()));
	ui->nameEdit->setEnabled(true);

	ui->alignSelect->setCurrentIndex(character->getAlignment());
	ui->alignSelect->setEnabled(true);

	ui->raceSelect->setCurrentIndex(character->getRaceId());
	ui->raceSelect->setEnabled(true);

	ui->genderSelect->setCurrentIndex(character->getGender());
	ui->genderSelect->setEnabled(true);

	updateAbilityDisplay();
	ui->abilityEdit->setEnabled(true);

	ui->gpValLabel->setText(QString::number(character->getGoldPieces()));
	ui->spValLabel->setText(QString::number(character->getSilverPieces()));
	ui->cpValLabel->setText(QString::number(character->getCopperPieces()));
	ui->equipAdd->setEnabled(true);

	updateFeatList();
	updateSkillsList();
	updateInventoryList();

	switch (character->getClassId())
	{
	case FIGHTER:
	{
		int focusIndex = ui->weaponFocusSelect->findText(
			QString::fromStdString(character->getSpecialClassOption()));
		if (focusIndex >= 0) {
			ui->weaponFocusSelect->setCurrentIndex(focusIndex);
		}
		break;
	}
	case CLERIC:
	{
		int godIndex = ui->godSelect->findText(
			QString::fromStdString(character->getSpecialClassOption()));
		if (godIndex >= 0) {
			ui->godSelect->setCurrentIndex(godIndex);
		}
		break;
	}
	case WIZARD:
	{
		int schoolIndex = ui->schoolSelect->findText(
			QString::fromStdString(character->getSpecialClassOption()));
		if (schoolIndex >= 0) {
			ui->schoolSelect->setCurrentIndex(schoolIndex);
		}
		break;
	}
	default:
		break;
	}

	loading = false;

	changeClassOptionsDisplay(character->getClassId());
	updateFeatsControls();
	updateSkillsControls();
	updateSpellbook();
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

void MainWindow::updateFeatsControls()
{
	ui->unspentFeatsCountLabel->setText(QString::number(
		character->getRemainingFeatCount()));
	if (character->getRemainingFeatCount() > 0) {
		ui->featsAdd->setEnabled(true);
	} else {
		ui->featsAdd->setEnabled(false);
	}
}

void MainWindow::updateSkillsControls()
{
	ui->unspentSkillsCountLabel->setText(QString::number(
		character->getRemainingSkillRanks()));
	if (character->getRemainingSkillRanks() > 0) {
		ui->skillsAdd->setEnabled(true);
	} else {
		ui->skillsAdd->setEnabled(false);
	}
}

void MainWindow::updateSpellbook()
{
	if (character != NULL && character->getClassId() == WIZARD) {
		ui->spellSlotLabel->setText(
			QString::number(character->spellSlotsRemaining()));
	}
}

void MainWindow::updateFeatList()
{
	ui->featsList->clear();
	for (auto feat : character->getFeats()) {
		ui->featsList->addItem(QString::fromStdString(feat.toString()));
	}
}

void MainWindow::updateSkillsList()
{
	ui->skillsList->clear();
	for (int i = 0; i <= SWIM; i++) {
		auto skill = character->getSkill(static_cast<CHARACTER_SKILLS>(i));
		if (skill.getRanks() > 0) {
			QListWidgetItem item;
			item.setText(QString::fromStdString(skill.toString()));
			item.setData(Qt::UserRole, skill.toSkillID());
			ui->skillsList->addItem(new QListWidgetItem(item));
		}
	}
}

void MainWindow::updateInventoryList()
{
	ui->equipList->clear();
	for (auto item : character->getInventory()) {
		ui->equipList->addItem(QString::fromStdString(item->getName()));
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
	featChooser->setAvailableFeats(character);
	featChooser->open();
}

void MainWindow::addFeat(PathfinderFeat feat)
{
	character->addFeat(feat);
	ui->featsList->addItem(QString::fromStdString(feat.toString()));
	unsavedChanges = true;
	updateFeatsControls();
}

void MainWindow::removeFeat()
{
	int index = ui->featsList->currentRow();
	if (index != -1) {
		character->removeFeat(index);
		auto remove = ui->featsList->takeItem(index);
		delete remove;
		unsavedChanges = true;
		updateFeatsControls();
	}
}

void MainWindow::featIndexChanged(int index)
{
	if (index == -1) {
		ui->featsRemove->setEnabled(false);
	} else {
		ui->featsRemove->setEnabled(true);
	}
}

void MainWindow::classValueChanged(QString value)
{
	if (!loading && character != NULL && character->getClassId() != ROGUE) {
		character->setClassSpecificValue(value.toStdString());
		unsavedChanges = true;
	}
}

void MainWindow::spellChanged(QListWidgetItem * spell)
{
	if (!loading && character != NULL && character->getClassId() == WIZARD) {
		if (spell->checkState() == Qt::Checked) {
			character->addWizardSpell(static_cast<WIZARD_SPELLS>(
				spell->data(Qt::UserRole).toInt()));
		} else if (spell->checkState() == Qt::Unchecked) {
			character->removeWizardSpell(static_cast<WIZARD_SPELLS>(
				spell->data(Qt::UserRole).toInt()));
		}
		unsavedChanges = true;
		updateSpellbook();
	}
}

void MainWindow::genderChanged(int gender)
{
	if (!loading && character != NULL && gender != character->getGender()) {
		character->setGender(static_cast<GENDER>(gender));
		unsavedChanges = true;
	}
}

void MainWindow::save()
{
	if (filename == "") {
		saveAs();
	} else {
		XmlDocument doc = pathfinderCharacterToXml(*character);
		XmlWriter writer(doc);
		if (writer.write(filename)) {
			unsavedChanges = false;
		} else {
			QMessageBox mbox;
			mbox.setText("Error saving data.");
			mbox.setDetailedText("The character was not saved.");
			mbox.exec();
		}
	}	
}

void MainWindow::saveAs()
{
	filename = QFileDialog::getSaveFileName(this, tr("Save as..."),
		QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), 
		tr("XML Files (*.xml)")).toStdString();
	if (filename != "") {
		save();
	}
}

void MainWindow::open()
{
	if (unsavedChanges && !promptToSaveChanges()) {
		return;
	}
	auto openFile = QFileDialog::getOpenFileName(this, tr("Select file to open"),
		QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), 
		tr("XML Files (*.xml)"));
	if (!openFile.isNull() && !openFile.isEmpty()) {
		if (character != NULL) {
			delete character;
			character = 0;
		}
		try {
			XmlReader reader(openFile.toStdString());
			XmlDocument doc = reader.getDocument();
			character = xmlToPathfinderCharacter(doc);
		} catch (const std::runtime_error& err) {
			QMessageBox msgBox;
			std::string message = err.what();
			if (character != 0) {
				delete character;
				character = 0;
			}
		}
		filename = openFile.toStdString();
		characterLoaded();
	}
}

void MainWindow::exportSheet()
{
	std::string sheetFile = QFileDialog::getSaveFileName(this, tr("Save as..."),
		QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), 
		tr("HTML Files (*.html)")).toStdString();
	HtmlSheet sheetContents;
	std::ofstream fs(sheetFile);
	if (!fs) {
		QMessageBox mbox;
		mbox.setText("Error exporting data.");
		mbox.setDetailedText("The character sheet was not created.");
		mbox.exec();
		return;
	}
	fs << sheetContents.generateCharacterSheet(character);
	fs.close();
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
		save();
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
