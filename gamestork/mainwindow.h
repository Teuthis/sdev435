#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "classselectwindow.h"
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

	PathfinderCharacter *character;
	
	bool unsavedChanges;



public slots:
	void newCharacter();

	void classSelected(CHARACTER_CLASS);

	void characterLoaded();

private:
	void changeClassOptionsDisplay(int classToShow = 0);

	bool promptToSaveChanges();

	void makeEditable(bool enabled = true);
};

#endif // MAINWINDOW_H
