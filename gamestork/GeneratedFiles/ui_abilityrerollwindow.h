/********************************************************************************
** Form generated from reading UI file 'abilityrerollwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABILITYREROLLWINDOW_H
#define UI_ABILITYREROLLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_AbilityRerollWindow
{
public:
    QGroupBox *roll1Group;
    QRadioButton *roll1Str;
    QRadioButton *roll1Dex;
    QLabel *roll1Label;
    QRadioButton *roll1Con;
    QRadioButton *roll1Int;
    QRadioButton *roll1Wis;
    QRadioButton *roll1Cha;
    QGroupBox *roll2Group;
    QRadioButton *roll2Str;
    QRadioButton *roll2Dex;
    QLabel *roll2Label;
    QRadioButton *roll2Con;
    QRadioButton *roll2Int;
    QRadioButton *roll2Wis;
    QRadioButton *roll2Cha;
    QGroupBox *roll3Group;
    QRadioButton *roll3Str;
    QRadioButton *roll3Dex;
    QLabel *roll3Label;
    QRadioButton *roll3Con;
    QRadioButton *roll3Int;
    QRadioButton *roll3Wis;
    QRadioButton *roll3Cha;
    QLabel *rollHeadingLabel;
    QLabel *abilityHeadingLabel;
    QGroupBox *roll4Group;
    QRadioButton *roll4Str;
    QRadioButton *roll4Dex;
    QLabel *roll4Label;
    QRadioButton *roll4Con;
    QRadioButton *roll4Int;
    QRadioButton *roll4Wis;
    QRadioButton *roll4Cha;
    QGroupBox *roll6Group;
    QRadioButton *roll6Str;
    QRadioButton *roll6Dex;
    QLabel *roll6Label;
    QRadioButton *roll6Con;
    QRadioButton *roll6Int;
    QRadioButton *roll6Wis;
    QRadioButton *roll6Cha;
    QGroupBox *roll5Group;
    QRadioButton *roll5Str;
    QRadioButton *roll5Dex;
    QLabel *roll5Label;
    QRadioButton *roll5Con;
    QRadioButton *roll5Int;
    QRadioButton *roll5Wis;
    QRadioButton *roll5Cha;
    QPushButton *rerollButton;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *AbilityRerollWindow)
    {
        if (AbilityRerollWindow->objectName().isEmpty())
            AbilityRerollWindow->setObjectName(QStringLiteral("AbilityRerollWindow"));
        AbilityRerollWindow->resize(388, 324);
        roll1Group = new QGroupBox(AbilityRerollWindow);
        roll1Group->setObjectName(QStringLiteral("roll1Group"));
        roll1Group->setGeometry(QRect(24, 36, 340, 36));
        roll1Str = new QRadioButton(roll1Group);
        roll1Str->setObjectName(QStringLiteral("roll1Str"));
        roll1Str->setGeometry(QRect(48, 10, 42, 16));
        roll1Dex = new QRadioButton(roll1Group);
        roll1Dex->setObjectName(QStringLiteral("roll1Dex"));
        roll1Dex->setGeometry(QRect(96, 10, 42, 16));
        roll1Label = new QLabel(roll1Group);
        roll1Label->setObjectName(QStringLiteral("roll1Label"));
        roll1Label->setGeometry(QRect(0, 0, 32, 32));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        roll1Label->setFont(font);
        roll1Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        roll1Con = new QRadioButton(roll1Group);
        roll1Con->setObjectName(QStringLiteral("roll1Con"));
        roll1Con->setGeometry(QRect(144, 10, 42, 16));
        roll1Int = new QRadioButton(roll1Group);
        roll1Int->setObjectName(QStringLiteral("roll1Int"));
        roll1Int->setGeometry(QRect(192, 10, 42, 16));
        roll1Wis = new QRadioButton(roll1Group);
        roll1Wis->setObjectName(QStringLiteral("roll1Wis"));
        roll1Wis->setGeometry(QRect(240, 10, 42, 16));
        roll1Cha = new QRadioButton(roll1Group);
        roll1Cha->setObjectName(QStringLiteral("roll1Cha"));
        roll1Cha->setGeometry(QRect(288, 10, 42, 16));
        roll2Group = new QGroupBox(AbilityRerollWindow);
        roll2Group->setObjectName(QStringLiteral("roll2Group"));
        roll2Group->setGeometry(QRect(24, 76, 340, 36));
        roll2Str = new QRadioButton(roll2Group);
        roll2Str->setObjectName(QStringLiteral("roll2Str"));
        roll2Str->setGeometry(QRect(48, 10, 42, 16));
        roll2Dex = new QRadioButton(roll2Group);
        roll2Dex->setObjectName(QStringLiteral("roll2Dex"));
        roll2Dex->setGeometry(QRect(96, 10, 42, 16));
        roll2Label = new QLabel(roll2Group);
        roll2Label->setObjectName(QStringLiteral("roll2Label"));
        roll2Label->setGeometry(QRect(0, 0, 32, 32));
        roll2Label->setFont(font);
        roll2Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        roll2Con = new QRadioButton(roll2Group);
        roll2Con->setObjectName(QStringLiteral("roll2Con"));
        roll2Con->setGeometry(QRect(144, 10, 42, 16));
        roll2Int = new QRadioButton(roll2Group);
        roll2Int->setObjectName(QStringLiteral("roll2Int"));
        roll2Int->setGeometry(QRect(192, 10, 42, 16));
        roll2Wis = new QRadioButton(roll2Group);
        roll2Wis->setObjectName(QStringLiteral("roll2Wis"));
        roll2Wis->setGeometry(QRect(240, 10, 42, 16));
        roll2Cha = new QRadioButton(roll2Group);
        roll2Cha->setObjectName(QStringLiteral("roll2Cha"));
        roll2Cha->setGeometry(QRect(288, 10, 42, 16));
        roll3Group = new QGroupBox(AbilityRerollWindow);
        roll3Group->setObjectName(QStringLiteral("roll3Group"));
        roll3Group->setGeometry(QRect(24, 116, 340, 36));
        roll3Str = new QRadioButton(roll3Group);
        roll3Str->setObjectName(QStringLiteral("roll3Str"));
        roll3Str->setGeometry(QRect(48, 10, 42, 16));
        roll3Dex = new QRadioButton(roll3Group);
        roll3Dex->setObjectName(QStringLiteral("roll3Dex"));
        roll3Dex->setGeometry(QRect(96, 10, 42, 16));
        roll3Label = new QLabel(roll3Group);
        roll3Label->setObjectName(QStringLiteral("roll3Label"));
        roll3Label->setGeometry(QRect(0, 0, 32, 32));
        roll3Label->setFont(font);
        roll3Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        roll3Con = new QRadioButton(roll3Group);
        roll3Con->setObjectName(QStringLiteral("roll3Con"));
        roll3Con->setGeometry(QRect(144, 10, 42, 16));
        roll3Int = new QRadioButton(roll3Group);
        roll3Int->setObjectName(QStringLiteral("roll3Int"));
        roll3Int->setGeometry(QRect(192, 10, 42, 16));
        roll3Wis = new QRadioButton(roll3Group);
        roll3Wis->setObjectName(QStringLiteral("roll3Wis"));
        roll3Wis->setGeometry(QRect(240, 10, 42, 16));
        roll3Cha = new QRadioButton(roll3Group);
        roll3Cha->setObjectName(QStringLiteral("roll3Cha"));
        roll3Cha->setGeometry(QRect(288, 10, 42, 16));
        rollHeadingLabel = new QLabel(AbilityRerollWindow);
        rollHeadingLabel->setObjectName(QStringLiteral("rollHeadingLabel"));
        rollHeadingLabel->setGeometry(QRect(16, 12, 71, 16));
        QFont font1;
        font1.setPointSize(10);
        rollHeadingLabel->setFont(font1);
        abilityHeadingLabel = new QLabel(AbilityRerollWindow);
        abilityHeadingLabel->setObjectName(QStringLiteral("abilityHeadingLabel"));
        abilityHeadingLabel->setGeometry(QRect(164, 12, 96, 16));
        abilityHeadingLabel->setFont(font1);
        roll4Group = new QGroupBox(AbilityRerollWindow);
        roll4Group->setObjectName(QStringLiteral("roll4Group"));
        roll4Group->setGeometry(QRect(24, 156, 340, 36));
        roll4Str = new QRadioButton(roll4Group);
        roll4Str->setObjectName(QStringLiteral("roll4Str"));
        roll4Str->setGeometry(QRect(48, 10, 42, 16));
        roll4Dex = new QRadioButton(roll4Group);
        roll4Dex->setObjectName(QStringLiteral("roll4Dex"));
        roll4Dex->setGeometry(QRect(96, 10, 42, 16));
        roll4Label = new QLabel(roll4Group);
        roll4Label->setObjectName(QStringLiteral("roll4Label"));
        roll4Label->setGeometry(QRect(0, 0, 32, 32));
        roll4Label->setFont(font);
        roll4Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        roll4Con = new QRadioButton(roll4Group);
        roll4Con->setObjectName(QStringLiteral("roll4Con"));
        roll4Con->setGeometry(QRect(144, 10, 42, 16));
        roll4Int = new QRadioButton(roll4Group);
        roll4Int->setObjectName(QStringLiteral("roll4Int"));
        roll4Int->setGeometry(QRect(192, 10, 42, 16));
        roll4Wis = new QRadioButton(roll4Group);
        roll4Wis->setObjectName(QStringLiteral("roll4Wis"));
        roll4Wis->setGeometry(QRect(240, 10, 42, 16));
        roll4Cha = new QRadioButton(roll4Group);
        roll4Cha->setObjectName(QStringLiteral("roll4Cha"));
        roll4Cha->setGeometry(QRect(288, 10, 42, 16));
        roll6Group = new QGroupBox(AbilityRerollWindow);
        roll6Group->setObjectName(QStringLiteral("roll6Group"));
        roll6Group->setGeometry(QRect(24, 236, 340, 36));
        roll6Str = new QRadioButton(roll6Group);
        roll6Str->setObjectName(QStringLiteral("roll6Str"));
        roll6Str->setGeometry(QRect(48, 10, 42, 16));
        roll6Dex = new QRadioButton(roll6Group);
        roll6Dex->setObjectName(QStringLiteral("roll6Dex"));
        roll6Dex->setGeometry(QRect(96, 10, 42, 16));
        roll6Label = new QLabel(roll6Group);
        roll6Label->setObjectName(QStringLiteral("roll6Label"));
        roll6Label->setGeometry(QRect(0, 0, 32, 32));
        roll6Label->setFont(font);
        roll6Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        roll6Con = new QRadioButton(roll6Group);
        roll6Con->setObjectName(QStringLiteral("roll6Con"));
        roll6Con->setGeometry(QRect(144, 10, 42, 16));
        roll6Int = new QRadioButton(roll6Group);
        roll6Int->setObjectName(QStringLiteral("roll6Int"));
        roll6Int->setGeometry(QRect(192, 10, 42, 16));
        roll6Wis = new QRadioButton(roll6Group);
        roll6Wis->setObjectName(QStringLiteral("roll6Wis"));
        roll6Wis->setGeometry(QRect(240, 10, 42, 16));
        roll6Cha = new QRadioButton(roll6Group);
        roll6Cha->setObjectName(QStringLiteral("roll6Cha"));
        roll6Cha->setGeometry(QRect(288, 10, 42, 16));
        roll5Group = new QGroupBox(AbilityRerollWindow);
        roll5Group->setObjectName(QStringLiteral("roll5Group"));
        roll5Group->setGeometry(QRect(24, 196, 340, 36));
        roll5Str = new QRadioButton(roll5Group);
        roll5Str->setObjectName(QStringLiteral("roll5Str"));
        roll5Str->setGeometry(QRect(48, 10, 42, 16));
        roll5Dex = new QRadioButton(roll5Group);
        roll5Dex->setObjectName(QStringLiteral("roll5Dex"));
        roll5Dex->setGeometry(QRect(96, 10, 42, 16));
        roll5Label = new QLabel(roll5Group);
        roll5Label->setObjectName(QStringLiteral("roll5Label"));
        roll5Label->setGeometry(QRect(0, 0, 32, 32));
        roll5Label->setFont(font);
        roll5Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        roll5Con = new QRadioButton(roll5Group);
        roll5Con->setObjectName(QStringLiteral("roll5Con"));
        roll5Con->setGeometry(QRect(144, 10, 42, 16));
        roll5Int = new QRadioButton(roll5Group);
        roll5Int->setObjectName(QStringLiteral("roll5Int"));
        roll5Int->setGeometry(QRect(192, 10, 42, 16));
        roll5Wis = new QRadioButton(roll5Group);
        roll5Wis->setObjectName(QStringLiteral("roll5Wis"));
        roll5Wis->setGeometry(QRect(240, 10, 42, 16));
        roll5Cha = new QRadioButton(roll5Group);
        roll5Cha->setObjectName(QStringLiteral("roll5Cha"));
        roll5Cha->setGeometry(QRect(288, 10, 42, 16));
        rerollButton = new QPushButton(AbilityRerollWindow);
        rerollButton->setObjectName(QStringLiteral("rerollButton"));
        rerollButton->setGeometry(QRect(297, 8, 75, 23));
        cancelButton = new QPushButton(AbilityRerollWindow);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(297, 290, 75, 23));
        okButton = new QPushButton(AbilityRerollWindow);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setEnabled(false);
        okButton->setGeometry(QRect(220, 290, 75, 23));

        retranslateUi(AbilityRerollWindow);
        QObject::connect(rerollButton, SIGNAL(clicked()), AbilityRerollWindow, SLOT(rerollScores()));
        QObject::connect(cancelButton, SIGNAL(clicked()), AbilityRerollWindow, SLOT(close()));
        QObject::connect(okButton, SIGNAL(clicked()), AbilityRerollWindow, SLOT(changesAccepted()));
        QObject::connect(roll1Cha, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll1Con, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll1Dex, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll1Int, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll1Str, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll1Wis, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll2Cha, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll2Con, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll2Dex, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll2Int, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll2Str, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll2Wis, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll3Cha, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll3Con, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll3Dex, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll3Int, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll3Str, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll3Wis, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll4Cha, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll4Con, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll4Dex, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll4Int, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll4Str, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll4Wis, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll5Con, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll5Cha, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll5Dex, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll5Int, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll5Str, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll5Wis, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll6Con, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll6Dex, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll6Int, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll6Str, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll6Wis, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));
        QObject::connect(roll6Cha, SIGNAL(toggled(bool)), AbilityRerollWindow, SLOT(testValidity()));

        QMetaObject::connectSlotsByName(AbilityRerollWindow);
    } // setupUi

    void retranslateUi(QDialog *AbilityRerollWindow)
    {
        AbilityRerollWindow->setWindowTitle(QApplication::translate("AbilityRerollWindow", "AbilityRerollWindow", Q_NULLPTR));
        roll1Group->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        roll1Str->setToolTip(QApplication::translate("AbilityRerollWindow", "Strength", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll1Str->setText(QApplication::translate("AbilityRerollWindow", "STR", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll1Dex->setToolTip(QApplication::translate("AbilityRerollWindow", "Dexterity", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll1Dex->setText(QApplication::translate("AbilityRerollWindow", "DEX", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll1Label->setToolTip(QApplication::translate("AbilityRerollWindow", "Current ability value", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll1Label->setText(QApplication::translate("AbilityRerollWindow", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll1Con->setToolTip(QApplication::translate("AbilityRerollWindow", "Constitution", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll1Con->setText(QApplication::translate("AbilityRerollWindow", "CON", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll1Int->setToolTip(QApplication::translate("AbilityRerollWindow", "Intelligence", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll1Int->setText(QApplication::translate("AbilityRerollWindow", "INT", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll1Wis->setToolTip(QApplication::translate("AbilityRerollWindow", "Wisdom", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll1Wis->setText(QApplication::translate("AbilityRerollWindow", "WIS", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll1Cha->setToolTip(QApplication::translate("AbilityRerollWindow", "Charisma", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll1Cha->setText(QApplication::translate("AbilityRerollWindow", "CHA", Q_NULLPTR));
        roll2Group->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        roll2Str->setToolTip(QApplication::translate("AbilityRerollWindow", "Strength", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll2Str->setText(QApplication::translate("AbilityRerollWindow", "STR", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll2Dex->setToolTip(QApplication::translate("AbilityRerollWindow", "Dexterity", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll2Dex->setText(QApplication::translate("AbilityRerollWindow", "DEX", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll2Label->setToolTip(QApplication::translate("AbilityRerollWindow", "Current ability value", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll2Label->setText(QApplication::translate("AbilityRerollWindow", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll2Con->setToolTip(QApplication::translate("AbilityRerollWindow", "Constitution", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll2Con->setText(QApplication::translate("AbilityRerollWindow", "CON", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll2Int->setToolTip(QApplication::translate("AbilityRerollWindow", "Intelligence", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll2Int->setText(QApplication::translate("AbilityRerollWindow", "INT", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll2Wis->setToolTip(QApplication::translate("AbilityRerollWindow", "Wisdom", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll2Wis->setText(QApplication::translate("AbilityRerollWindow", "WIS", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll2Cha->setToolTip(QApplication::translate("AbilityRerollWindow", "Charisma", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll2Cha->setText(QApplication::translate("AbilityRerollWindow", "CHA", Q_NULLPTR));
        roll3Group->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        roll3Str->setToolTip(QApplication::translate("AbilityRerollWindow", "Strength", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll3Str->setText(QApplication::translate("AbilityRerollWindow", "STR", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll3Dex->setToolTip(QApplication::translate("AbilityRerollWindow", "Dexterity", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll3Dex->setText(QApplication::translate("AbilityRerollWindow", "DEX", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll3Label->setToolTip(QApplication::translate("AbilityRerollWindow", "Current ability value", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll3Label->setText(QApplication::translate("AbilityRerollWindow", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll3Con->setToolTip(QApplication::translate("AbilityRerollWindow", "Constitution", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll3Con->setText(QApplication::translate("AbilityRerollWindow", "CON", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll3Int->setToolTip(QApplication::translate("AbilityRerollWindow", "Intelligence", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll3Int->setText(QApplication::translate("AbilityRerollWindow", "INT", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll3Wis->setToolTip(QApplication::translate("AbilityRerollWindow", "Wisdom", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll3Wis->setText(QApplication::translate("AbilityRerollWindow", "WIS", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll3Cha->setToolTip(QApplication::translate("AbilityRerollWindow", "Charisma", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll3Cha->setText(QApplication::translate("AbilityRerollWindow", "CHA", Q_NULLPTR));
        rollHeadingLabel->setText(QApplication::translate("AbilityRerollWindow", "Roll Result", Q_NULLPTR));
        abilityHeadingLabel->setText(QApplication::translate("AbilityRerollWindow", "Assigned Ability", Q_NULLPTR));
        roll4Group->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        roll4Str->setToolTip(QApplication::translate("AbilityRerollWindow", "Strength", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll4Str->setText(QApplication::translate("AbilityRerollWindow", "STR", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll4Dex->setToolTip(QApplication::translate("AbilityRerollWindow", "Dexterity", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll4Dex->setText(QApplication::translate("AbilityRerollWindow", "DEX", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll4Label->setToolTip(QApplication::translate("AbilityRerollWindow", "Current ability value", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll4Label->setText(QApplication::translate("AbilityRerollWindow", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll4Con->setToolTip(QApplication::translate("AbilityRerollWindow", "Constitution", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll4Con->setText(QApplication::translate("AbilityRerollWindow", "CON", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll4Int->setToolTip(QApplication::translate("AbilityRerollWindow", "Intelligence", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll4Int->setText(QApplication::translate("AbilityRerollWindow", "INT", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll4Wis->setToolTip(QApplication::translate("AbilityRerollWindow", "Wisdom", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll4Wis->setText(QApplication::translate("AbilityRerollWindow", "WIS", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll4Cha->setToolTip(QApplication::translate("AbilityRerollWindow", "Charisma", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll4Cha->setText(QApplication::translate("AbilityRerollWindow", "CHA", Q_NULLPTR));
        roll6Group->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        roll6Str->setToolTip(QApplication::translate("AbilityRerollWindow", "Strength", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll6Str->setText(QApplication::translate("AbilityRerollWindow", "STR", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll6Dex->setToolTip(QApplication::translate("AbilityRerollWindow", "Dexterity", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll6Dex->setText(QApplication::translate("AbilityRerollWindow", "DEX", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll6Label->setToolTip(QApplication::translate("AbilityRerollWindow", "Current ability value", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll6Label->setText(QApplication::translate("AbilityRerollWindow", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll6Con->setToolTip(QApplication::translate("AbilityRerollWindow", "Constitution", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll6Con->setText(QApplication::translate("AbilityRerollWindow", "CON", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll6Int->setToolTip(QApplication::translate("AbilityRerollWindow", "Intelligence", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll6Int->setText(QApplication::translate("AbilityRerollWindow", "INT", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll6Wis->setToolTip(QApplication::translate("AbilityRerollWindow", "Wisdom", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll6Wis->setText(QApplication::translate("AbilityRerollWindow", "WIS", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll6Cha->setToolTip(QApplication::translate("AbilityRerollWindow", "Charisma", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll6Cha->setText(QApplication::translate("AbilityRerollWindow", "CHA", Q_NULLPTR));
        roll5Group->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        roll5Str->setToolTip(QApplication::translate("AbilityRerollWindow", "Strength", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll5Str->setText(QApplication::translate("AbilityRerollWindow", "STR", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll5Dex->setToolTip(QApplication::translate("AbilityRerollWindow", "Dexterity", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll5Dex->setText(QApplication::translate("AbilityRerollWindow", "DEX", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll5Label->setToolTip(QApplication::translate("AbilityRerollWindow", "Current ability value", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll5Label->setText(QApplication::translate("AbilityRerollWindow", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll5Con->setToolTip(QApplication::translate("AbilityRerollWindow", "Constitution", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll5Con->setText(QApplication::translate("AbilityRerollWindow", "CON", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll5Int->setToolTip(QApplication::translate("AbilityRerollWindow", "Intelligence", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll5Int->setText(QApplication::translate("AbilityRerollWindow", "INT", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll5Wis->setToolTip(QApplication::translate("AbilityRerollWindow", "Wisdom", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll5Wis->setText(QApplication::translate("AbilityRerollWindow", "WIS", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roll5Cha->setToolTip(QApplication::translate("AbilityRerollWindow", "Charisma", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        roll5Cha->setText(QApplication::translate("AbilityRerollWindow", "CHA", Q_NULLPTR));
        rerollButton->setText(QApplication::translate("AbilityRerollWindow", "Reroll", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("AbilityRerollWindow", "Cancel", Q_NULLPTR));
        okButton->setText(QApplication::translate("AbilityRerollWindow", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AbilityRerollWindow: public Ui_AbilityRerollWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABILITYREROLLWINDOW_H
