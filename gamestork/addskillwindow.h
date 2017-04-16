//-----------------------------------------------------------------------------
/**
File: addskillwindow.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Header file for skill chooser window
*/
//-----------------------------------------------------------------------------

#pragma once

#include <QDialog>
#include "ui_addskillwindow.h"

class AddSkillWindow : public QDialog, public Ui::AddSkillWindow
{
	/// QT required reference for slots/signals system
	Q_OBJECT

public:
	/// Constructs a new AddSkillWindow object
	/// @param parent Pointer to the parent window
	AddSkillWindow(QWidget *parent = Q_NULLPTR);

	/// Destroys the AddSkillWindow object
	~AddSkillWindow();

	/// Adds a skill to the list of choices
	/// @param name The display name of the skill to add
	/// @param id The id number of the skill
	void addSkillOption(QString name, int id);

public slots:
	/// Triggered when the ok button is clicked
	/// Validates selection, updates choices, and emits the skillAdded signal
	void skillChosen();

signals:
	/// Sends a QListWidgetItem containing information about the chosen
	/// skill to all connected slots
	void skillAdded(QListWidgetItem);
};
