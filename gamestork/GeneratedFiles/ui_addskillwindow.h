/********************************************************************************
** Form generated from reading UI file 'addskillwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSKILLWINDOW_H
#define UI_ADDSKILLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddSkillWindow
{
public:
    QListWidget *skillsList;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *headingLabel;

    void setupUi(QDialog *AddSkillWindow)
    {
        if (AddSkillWindow->objectName().isEmpty())
            AddSkillWindow->setObjectName(QStringLiteral("AddSkillWindow"));
        AddSkillWindow->setWindowModality(Qt::ApplicationModal);
        AddSkillWindow->resize(196, 210);
        skillsList = new QListWidget(AddSkillWindow);
        skillsList->setObjectName(QStringLiteral("skillsList"));
        skillsList->setGeometry(QRect(12, 32, 172, 144));
        okButton = new QPushButton(AddSkillWindow);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(30, 180, 75, 23));
        cancelButton = new QPushButton(AddSkillWindow);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(109, 180, 75, 23));
        headingLabel = new QLabel(AddSkillWindow);
        headingLabel->setObjectName(QStringLiteral("headingLabel"));
        headingLabel->setGeometry(QRect(12, 12, 72, 13));

        retranslateUi(AddSkillWindow);
        QObject::connect(cancelButton, SIGNAL(clicked()), AddSkillWindow, SLOT(close()));
        QObject::connect(okButton, SIGNAL(clicked()), AddSkillWindow, SLOT(skillChosen()));

        QMetaObject::connectSlotsByName(AddSkillWindow);
    } // setupUi

    void retranslateUi(QDialog *AddSkillWindow)
    {
        AddSkillWindow->setWindowTitle(QApplication::translate("AddSkillWindow", "Add Skill", Q_NULLPTR));
        okButton->setText(QApplication::translate("AddSkillWindow", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("AddSkillWindow", "Cancel", Q_NULLPTR));
        headingLabel->setText(QApplication::translate("AddSkillWindow", "Available skills:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddSkillWindow: public Ui_AddSkillWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSKILLWINDOW_H
