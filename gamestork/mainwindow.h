//-----------------------------------------------------------------------------
/**
File: mainwindow.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Header file for main application window
*/
//-----------------------------------------------------------------------------

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QCloseEvent>
#include <QStandardPaths>
#include "classselectwindow.h"
#include "abilityrerollwindow.h"
#include "addskillwindow.h"
#include "featchooserwindow.h"
#include "equipmentchooserwindow.h"
#include "welcomewindow.h"
#include <PathfinderEnumerations.h>
#include <PathfinderCharacter.h>
#include <XmlReader.h>
#include <XmlWriter.h>
#include <HtmlSheet.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	/// Required QT reference
    Q_OBJECT

public:
	/// Constructs a new MainWindow object
	/// @param parent Pointer to the window's parent object
    explicit MainWindow(QWidget *parent = 0);

	/// Destroys the MainWindow object
    ~MainWindow();

	/// Fired when the window is closing
	/// @param event Pointer to information about the close event
	void closeEvent(QCloseEvent *event);

private:
	/// Pointer to the window controls object
    Ui::MainWindow *ui;

	/// Pointer to the welcome window
	WelcomeWindow *welcomeWindow;

	/// Pointer to the create new character dialog
	ClassSelectWindow *newCharWindow;

	/// Pointer to the ability editor dialog
	AbilityRerollWindow *abilityEditor;

	/// Pointer to the skill chooser dialog
	AddSkillWindow *addSkillWindow;

	/// Pointer to the feat chooser dialog
	FeatChooserWindow *featChooser;

	/// Pointer to equipment chooser dialog
	EquipmentChooserWindow *equipmentChooser;

	/// Pointer to the current character data
	PathfinderCharacter *character;
	
	/// True if the character has been edited since last save
	bool unsavedChanges;

	/// The filename of the currently open file
	std::string filename;

	/// Set to true while a character si being loaded from a file
	/// Prevents unnecessary change signals
	bool loading;


// QT slots
public slots:

	/// Triggered when the new character action is triggered
	/// Opens the new character dialog
	void newCharacter();

	/// Triggered when user selects a class for a new character
	/// Instantiates a new character of the selected class
	/// @param chosenClass The class type of the new character
	void classSelected(CHARACTER_CLASS);

	/// Triggered when the alignment combobox is changed
	/// Updates the character object with the new alignment value
	/// @param selectedAlignment The index of the new selected value
	void editAlignment(int);

	/// Triggered when the character name textbox is edited
	/// Updates the character object with the new name value
	/// @param newName The current value of the name textbox
	void editName(QString);

	/// Triggered when the race combobox is changed
	/// Updates the character object with the new race value
	/// @param raceIndex The index of the new selected value
	void editRace(int);

	/// Triggered when the user clicks OK in the ability editor
	/// Updates the character object with the new ability scores
	/// @param str The new strength value
	/// @param dex The new dexterity value
	/// @param con The new constitution value
	/// @param int The new intelligence value
	/// @param wis The new wisdom value
	/// @param cha The new charisma value
	void editAbilities(int, int, int, int, int, int);

	/// Triggered when the Edit button in the abilities frame is clicked
	/// Opens the ability editor dialog
	void openAbilityEditor();

	/// Triggered when the add skill button is clicked
	/// Opens the skill chooser dialog
	void openSkillChooser();

	/// Triggered when the ok button in the skill chooser is clicked
	/// Marks the skill stored in the list item data as trained in the 
	/// character object
	/// @param skill A list item containing the skill id and name
	void addSkill(QListWidgetItem);

	/// Triggered when the remove skill button is clicked
	/// Marks the currently selected skill as untrained in the character object
	void removeSkill();

	/// Triggered when the selected item in the skills list is changed
	/// Toggles enabled status of remove skill button 
	/// @param index The currently selected index
	void skillIndexChanged(int);

	/// Triggered when the add equipment button is clicked
	/// Opens the equipment chooser dialog
	void openEquipmentChooser();

	/// Triggered when the ok button in the equipment chooser is clicked
	/// Adds the given item to the character object and deducts cost
	/// @param item The item to acquire
	void addItem(std::shared_ptr<InventoryItem>);

	/// Triggered when the remove item button is clicked
	/// Removes the selected item from the character inventory and refunds
	/// the original cost
	void removeItem();

	/// Triggered when the selected item in the equipment list is changed
	/// Toggles enabled status of remove equipment button 
	/// @param index The currently selected index
	void itemIndexChanged(int);

	/// Triggered when the add feat button is clicked
	/// Opens the feat chooser dialog
	void openFeatChooser();

	/// Triggered when the ok button in the feat chooser is clicked
	/// Trains the character object in the selected feat
	/// @param feat A list item containing the feat object as data
	void addFeat(PathfinderFeat);

	/// Triggered when the remove feat button is clicked
	/// Removes the selected feat from the character object
	void removeFeat();

	/// Triggered when the selected item in the feat list is changed
	/// Toggles enabled status of remove feat button 
	/// @param index The currently selected index
	void featIndexChanged(int);

	/// Triggered when one of the class-specific combo boxes is changed
	/// Updates the character with the new value
	/// @param value The new value to set
	void classValueChanged(QString);

	/// Triggered when a Wizard spellbook item is checked or unchecked
	/// Updates the character's known spell list
	/// @param spell The changed spell
	void spellChanged(QListWidgetItem* spell);

	/// Triggered when the gender dropdown list is changed
	/// Updates the character's gender
	/// @param gender The new gender value
	void genderChanged(int);

	/// Triggered from clicking save
	/// Saves the character
	void save();

	/// Triggered from clicking save as or clicking save with no filename set
	/// Prompts for a filename, then calls save()
	void saveAs();

	/// Triggered from clicking open
	/// Opens a character
	void open();

	/// Triggered by clicking Export
	/// Exports the character to a printable HTML document
	void exportSheet();

private:
	/// Sets visibility of the class-specfic options menus
	/// @param The class to set visible
	void changeClassOptionsDisplay(int classToShow = 0);

	/// Provides the user an opportunity to write unsaved changes to disk
	/// @return false if the user selects cancel, true otherwise
	bool promptToSaveChanges();

	/// Sets the enabled state of most user controls
	/// @param enabled The enabled state to set
	void makeEditable(bool enabled = true);

	/// Updates gui display elements based on loaded character's values
	void characterLoaded();

	/// Updates the ability section of the gui
	void updateAbilityDisplay();

	/// Prompts the user to select the human's +2 ability bonus
	/// @return The id of the selected ability
	int setHumanBonusAbility();

	/// Changes the enabled status of the feat editing controls based on the 
	/// available feat selections remaining
	void updateFeatsControls();

	/// Changes the enabled status of the skill editing controls based on the 
	/// available skill selections remaining
	void updateSkillsControls();

	/// Sets the checked/unchecked status of wizard spells based on the loaded
	/// character's values
	void updateSpellbook();

	/// Sets the contents of the feat list based on the loaded 
	/// character's values
	void updateFeatList();

	/// Sets the contents of the skills list based on the loaded 
	/// character's values
	void updateSkillsList();

	/// Sets the contents of the inventory list based on the loaded 
	/// character's values
	void updateInventoryList();
};

#endif // MAINWINDOW_H
