#pragma once

#include <QDialog>
#include "ui_classselectwindow.h"
#include <PathfinderEnumerations.h>

class ClassSelectWindow : public QDialog, public Ui::ClassSelectWindow
{
	Q_OBJECT

public:
	ClassSelectWindow(QWidget *parent = Q_NULLPTR);
	~ClassSelectWindow();

public slots:
	void clericClicked();

	void fighterClicked();

	void rogueClicked();

	void wizardClicked();

signals:
	void classChosen(CHARACTER_CLASS);
};
