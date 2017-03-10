#pragma once

#include <QDialog>
#include "ui_addskillwindow.h"

class AddSkillWindow : public QDialog, public Ui::AddSkillWindow
{
	Q_OBJECT

public:
	AddSkillWindow(QWidget *parent = Q_NULLPTR);
	~AddSkillWindow();
};
