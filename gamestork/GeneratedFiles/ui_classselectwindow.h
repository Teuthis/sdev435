/********************************************************************************
** Form generated from reading UI file 'classselectwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSSELECTWINDOW_H
#define UI_CLASSSELECTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ClassSelectWindow
{
public:
    QLabel *headingLabel;
    QPushButton *clericButton;
    QPushButton *fighterButton;
    QPushButton *rogueButton;
    QPushButton *wizardButton;
    QLabel *clericLabel;
    QLabel *fighterLabel;
    QLabel *rogueLabel;
    QLabel *wizardLabel;

    void setupUi(QDialog *ClassSelectWindow)
    {
        if (ClassSelectWindow->objectName().isEmpty())
            ClassSelectWindow->setObjectName(QStringLiteral("ClassSelectWindow"));
        ClassSelectWindow->setWindowModality(Qt::ApplicationModal);
        ClassSelectWindow->resize(592, 224);
        headingLabel = new QLabel(ClassSelectWindow);
        headingLabel->setObjectName(QStringLiteral("headingLabel"));
        headingLabel->setGeometry(QRect(16, 12, 560, 24));
        QFont font;
        font.setPointSize(16);
        headingLabel->setFont(font);
        headingLabel->setAlignment(Qt::AlignCenter);
        clericButton = new QPushButton(ClassSelectWindow);
        clericButton->setObjectName(QStringLiteral("clericButton"));
        clericButton->setGeometry(QRect(16, 48, 128, 128));
        fighterButton = new QPushButton(ClassSelectWindow);
        fighterButton->setObjectName(QStringLiteral("fighterButton"));
        fighterButton->setGeometry(QRect(160, 48, 128, 128));
        rogueButton = new QPushButton(ClassSelectWindow);
        rogueButton->setObjectName(QStringLiteral("rogueButton"));
        rogueButton->setGeometry(QRect(304, 48, 128, 128));
        wizardButton = new QPushButton(ClassSelectWindow);
        wizardButton->setObjectName(QStringLiteral("wizardButton"));
        wizardButton->setGeometry(QRect(448, 48, 128, 128));
        clericLabel = new QLabel(ClassSelectWindow);
        clericLabel->setObjectName(QStringLiteral("clericLabel"));
        clericLabel->setGeometry(QRect(16, 184, 128, 16));
        clericLabel->setAlignment(Qt::AlignCenter);
        fighterLabel = new QLabel(ClassSelectWindow);
        fighterLabel->setObjectName(QStringLiteral("fighterLabel"));
        fighterLabel->setGeometry(QRect(160, 184, 128, 16));
        fighterLabel->setAlignment(Qt::AlignCenter);
        rogueLabel = new QLabel(ClassSelectWindow);
        rogueLabel->setObjectName(QStringLiteral("rogueLabel"));
        rogueLabel->setGeometry(QRect(304, 184, 128, 16));
        rogueLabel->setAlignment(Qt::AlignCenter);
        wizardLabel = new QLabel(ClassSelectWindow);
        wizardLabel->setObjectName(QStringLiteral("wizardLabel"));
        wizardLabel->setGeometry(QRect(448, 184, 128, 16));
        wizardLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(ClassSelectWindow);
        QObject::connect(clericButton, SIGNAL(clicked()), ClassSelectWindow, SLOT(clericClicked()));
        QObject::connect(fighterButton, SIGNAL(clicked()), ClassSelectWindow, SLOT(fighterClicked()));
        QObject::connect(rogueButton, SIGNAL(clicked()), ClassSelectWindow, SLOT(rogueClicked()));
        QObject::connect(wizardButton, SIGNAL(clicked()), ClassSelectWindow, SLOT(wizardClicked()));

        QMetaObject::connectSlotsByName(ClassSelectWindow);
    } // setupUi

    void retranslateUi(QDialog *ClassSelectWindow)
    {
        ClassSelectWindow->setWindowTitle(QApplication::translate("ClassSelectWindow", "Select character class", Q_NULLPTR));
        headingLabel->setText(QApplication::translate("ClassSelectWindow", "Choose Character Class", Q_NULLPTR));
        clericButton->setText(QApplication::translate("ClassSelectWindow", "Cleric", Q_NULLPTR));
        fighterButton->setText(QApplication::translate("ClassSelectWindow", "Fighter", Q_NULLPTR));
        rogueButton->setText(QApplication::translate("ClassSelectWindow", "Rogue", Q_NULLPTR));
        wizardButton->setText(QApplication::translate("ClassSelectWindow", "Wizard", Q_NULLPTR));
        clericLabel->setText(QApplication::translate("ClassSelectWindow", "Cleric", Q_NULLPTR));
        fighterLabel->setText(QApplication::translate("ClassSelectWindow", "Fighter", Q_NULLPTR));
        rogueLabel->setText(QApplication::translate("ClassSelectWindow", "Rogue", Q_NULLPTR));
        wizardLabel->setText(QApplication::translate("ClassSelectWindow", "Wizard", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClassSelectWindow: public Ui_ClassSelectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSSELECTWINDOW_H
