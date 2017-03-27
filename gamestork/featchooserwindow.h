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
	Q_OBJECT

public:
	FeatChooserWindow(QWidget *parent = Q_NULLPTR);
	~FeatChooserWindow();

	void setAvailableFeats(const PathfinderCharacter * const character);

public slots:
	void featChosen();

signals:
	void featAdded(PathfinderFeat);

private:
	std::vector<PathfinderFeat> allFeats;
};
