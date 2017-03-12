#include "addskillwindow.h"

AddSkillWindow::AddSkillWindow(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}

AddSkillWindow::~AddSkillWindow()
{
}

void AddSkillWindow::addSkillOption(QString name, int id)
{
	QListWidgetItem *item = new QListWidgetItem(name);
	item->setData(Qt::UserRole, id);
	skillsList->addItem(item);
	//skillsList->addItem(name);
}

void AddSkillWindow::skillChosen()
{
	if (skillsList->currentRow() != -1) {
		emit skillAdded(*(skillsList->currentItem()));
	}
	QListWidgetItem *item = skillsList->takeItem(0);
	while (item) {
		delete item;
		item = skillsList->takeItem(0);
	}
	this->close();
}