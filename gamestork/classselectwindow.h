//-----------------------------------------------------------------------------
/**
File: classselectwindow.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Header file for new character/class selection window
*/
//-----------------------------------------------------------------------------

#pragma once

#include <QDialog>
#include "ui_classselectwindow.h"
#include <PathfinderEnumerations.h>

class ClassSelectWindow : public QDialog, public Ui::ClassSelectWindow
{
	/// QT required reference for slots/signals system
	Q_OBJECT

public:
	/// Constructs a new ClassSelectWindow object
	/// @param parent Pointer to the parent window
	ClassSelectWindow(QWidget *parent = Q_NULLPTR);

	/// Destroys the ClassSelectWindow object
	~ClassSelectWindow();

public slots:
	/// Triggered when the cleric class is chosen
	/// Emits the classChosen signal with the cleric argument
	void clericClicked();

	/// Triggered when the fighter class is chosen
	/// Emits the classChosen signal with the fighter argument
	void fighterClicked();

	/// Triggered when the rogue class is chosen
	/// Emits the classChosen signal with the rogue argument
	void rogueClicked();

	/// Triggered when the wizard class is chosen
	/// Emits the classChosen signal with the wizard argument
	void wizardClicked();

signals:
	/// Sends the selected class to all connected slots
	void classChosen(CHARACTER_CLASS);
};
