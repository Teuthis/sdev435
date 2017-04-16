//-----------------------------------------------------------------------------
/**
File: welcomewindow.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Implementation file for the welcome window that displays on launch
*/
//-----------------------------------------------------------------------------

#include "welcomewindow.h"


WelcomeWindow::WelcomeWindow(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	QPoint thisCenter = mapToGlobal(rect().center());
	QPoint parentCenter = parent->window()->mapToGlobal(
		parent->window()->rect().center());
	move(parentCenter - thisCenter);
}


WelcomeWindow::~WelcomeWindow()
{
}


void WelcomeWindow::chooseNew() 
{
	this->close();
	emit newChar();
}


void WelcomeWindow::chooseOpen()
{
	this->close();
	emit openChar();
}


void WelcomeWindow::chooseQuit()
{
	this->close();
	emit quitGamestork();
}