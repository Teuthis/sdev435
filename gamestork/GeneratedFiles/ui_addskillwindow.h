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
    QPushButton *pushButton;
    QPushButton *cancelButton;
    QLabel *headingLabel;

    void setupUi(QDialog *AddSkillWindow)
    {
        if (AddSkillWindow->objectName().isEmpty())
            AddSkillWindow->setObjectName(QStringLiteral("AddSkillWindow"));
        AddSkillWindow->resize(400, 300);
        skillsList = new QListWidget(AddSkillWindow);
        skillsList->setObjectName(QStringLiteral("skillsList"));
        skillsList->setGeometry(QRect(50, 40, 256, 192));
        pushButton = new QPushButton(AddSkillWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 260, 75, 23));
        cancelButton = new QPushButton(AddSkillWindow);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(230, 260, 75, 23));
        headingLabel = new QLabel(AddSkillWindow);
        headingLabel->setObjectName(QStringLiteral("headingLabel"));
        headingLabel->setGeometry(QRect(70, 10, 47, 13));

        retranslateUi(AddSkillWindow);

        QMetaObject::connectSlotsByName(AddSkillWindow);
    } // setupUi

    void retranslateUi(QDialog *AddSkillWindow)
    {
        AddSkillWindow->setWindowTitle(QApplication::translate("AddSkillWindow", "AddSkillWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AddSkillWindow", "PushButton", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("AddSkillWindow", "Cancel", Q_NULLPTR));
        headingLabel->setText(QApplication::translate("AddSkillWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddSkillWindow: public Ui_AddSkillWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSKILLWINDOW_H
