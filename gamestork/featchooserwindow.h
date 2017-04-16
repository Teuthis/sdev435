//-----------------------------------------------------------------------------
/**
File: featchooserwindow.h
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Header file for feat chooser window
*/
//-----------------------------------------------------------------------------

#pragma once

#include <QDialog>
#include <vector>
#include <PathfinderFeat.h>
#include <XmlDocument.h>
#include <XmlReader.h>
#include <PathfinderCharacter.h>
#include "ui_featchooserwindow.h"

class FeatChooserWindow : public QDialog, public Ui::FeatChooserWindow
{
	/// QT required reference for slots/signals system
	Q_OBJECT

public:
	/// Constructs a new AbilityRerollWindow object
	/// @param parent Pointer to the parent window
	FeatChooserWindow(QWidget *parent = Q_NULLPTR);

	/// Destroys the FeatChooserWindow object
	~FeatChooserWindow();

	/// Populates the selection list based on which prerequisites the 
	/// character meets
	/// @param character Pointer to the character
	void setAvailableFeats(const PathfinderCharacter * const character);

public slots:
	/// Triggered when the ok button is clicked
	/// Emits the featAdded signal with the selected feat
	void featChosen();

signals:
	/// Sends the chosen feat to all subscribed slots
	void featAdded(PathfinderFeat);

private:
	/// The complete set of feats
	std::vector<PathfinderFeat> allFeats;
};
