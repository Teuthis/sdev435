#pragma once

#include <QDialog>
#include "ui_featchooserwindow.h"

class FeatChooserWindow : public QDialog, public Ui::FeatChooserWindow
{
	Q_OBJECT

public:
	FeatChooserWindow(QWidget *parent = Q_NULLPTR);
	~FeatChooserWindow();

public slots:
	void featChosen();

signals:
	void featAdded(QListWidgetItem);
};
