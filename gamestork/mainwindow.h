#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include "classselectwindow.h"
#include "abilityrerollwindow.h"
#include "addskillwindow.h"
#include "equipmentchooserwindow.h"
#include <PathfinderEnumerations.h>
#include <PathfinderCharacter.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

	ClassSelectWindow *newCharWindow;

	AbilityRerollWindow *abilityEditor;

	AddSkillWindow *addSkillWindow;

	EquipmentChooserWindow *equipmentChooser;

	PathfinderCharacter *character;
	
	bool unsavedChanges;



public slots:
	void newCharacter();

	void classSelected(CHARACTER_CLASS);

	void editAlignment(int);

	void editName(QString);

	void editRace(int);

	void editAbilities(int, int, int, int, int, int);

	void openAbilityEditor();

	void openSkillChooser();

	void addSkill(QListWidgetItem);

	void removeSkill();

	void skillIndexChanged(int);

	void openEquipmentChooser();

	void addItem(InventoryItem);

	void removeItem();

	void itemIndexChanged(int);

private:
	void changeClassOptionsDisplay(int classToShow = 0);

	bool promptToSaveChanges();

	void makeEditable(bool enabled = true);

	void characterLoaded();

	void updateAbilityDisplay();

	int setHumanBonusAbility();

	void updateFeatsDisplay();

	void updateSkillsDisplay();
};

#endif // MAINWINDOW_H
