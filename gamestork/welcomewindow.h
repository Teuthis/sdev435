//-----------------------------------------------------------------------------
/**
File: welcomewindow.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Header file for the welcome window that displays on launch
*/
//-----------------------------------------------------------------------------

#pragma once

#include <QDialog>
#include "ui_welcomewindow.h"

class WelcomeWindow : public QDialog, public Ui::WelcomeWindow
{
	/// Required QT reference
	Q_OBJECT

public:
	/// Constructs a new WelcomeWindow object
	/// @param parent Pointer to the window's parent object
	WelcomeWindow(QWidget *parent = Q_NULLPTR);

	/// Destroys the WelcomeWindow object
	~WelcomeWindow();

public slots:
	/// Triggered when the new character button is clicked
	/// Emits the newChar() signal
	void chooseNew();

	/// Triggered when the open character button is clicked
	/// Emits the openChar() signal
	void chooseOpen();

	/// Triggered when the quit application button is clicked
	/// Emits the quitGamestork() signal
	void chooseQuit();

signals:
	/// Sends a newChar notification to subscribed slots
	void newChar();

	/// Sends an openChar notification to subscribed slots
	void openChar();

	/// Sends a quitGamestork notification to subscribed slots
	void quitGamestork();
};
