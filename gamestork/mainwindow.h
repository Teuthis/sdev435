#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include "classselectwindow.h"
#include "abilityrerollwindow.h"
#include "addskillwindow.h"
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

private:
	void changeClassOptionsDisplay(int classToShow = 0);

	bool promptToSaveChanges();

	void makeEditable(bool enabled = true);

	void characterLoaded();

	void updateAbilityDisplay();

	int setHumanBonusAbility();
};

#endif // MAINWINDOW_H
