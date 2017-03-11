/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Character;
    QAction *actionOpen_Character;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExport_Character_Sheet;
    QAction *actionExit;
    QWidget *centralWidget;
    QGroupBox *abilityGroup;
    QLabel *strLabel;
    QLabel *dexLabel;
    QLabel *conLabel;
    QLabel *intLabel;
    QLabel *wisLabel;
    QLabel *chaLabel;
    QLabel *strVal;
    QLabel *dexVal;
    QLabel *conVal;
    QLabel *intVal;
    QLabel *wisVal;
    QLabel *chaVal;
    QPushButton *abilityEdit;
    QGroupBox *skillsGroup;
    QListWidget *skillsList;
    QPushButton *skillsAdd;
    QLabel *unspentSkillsLabel;
    QPushButton *skillsRemove;
    QGroupBox *featsGroup;
    QListWidget *featsList;
    QPushButton *featsAdd;
    QLabel *unspentFeatsLabel;
    QPushButton *featsRemove;
    QGroupBox *generalGroup;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *alignLabel;
    QComboBox *alignSelect;
    QLabel *raceLabel;
    QComboBox *raceSelect;
    QLabel *genderLabel;
    QComboBox *genderSelect;
    QGroupBox *wizardGroup;
    QComboBox *schoolSelect;
    QLabel *schoolLabel;
    QListWidget *spellbookList;
    QLabel *spellbookLabel;
    QGroupBox *fighterGroup;
    QLabel *weaponFocusLabel;
    QComboBox *weaponFocusSelect;
    QGroupBox *rogueGroup;
    QLabel *rogueLabel;
    QGroupBox *clericGroup;
    QComboBox *godSelect;
    QLabel *godLabel;
    QGroupBox *equipmentGroup;
    QLabel *moneyLabel;
    QLabel *gpValLabel;
    QLabel *spValLabel;
    QLabel *cpValLabel;
    QLabel *gpLabel;
    QLabel *spLabel;
    QLabel *cpLabel;
    QPushButton *equipRemove;
    QListWidget *listWidget;
    QPushButton *equipAdd;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(664, 411);
        actionNew_Character = new QAction(MainWindow);
        actionNew_Character->setObjectName(QStringLiteral("actionNew_Character"));
        actionOpen_Character = new QAction(MainWindow);
        actionOpen_Character->setObjectName(QStringLiteral("actionOpen_Character"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionExport_Character_Sheet = new QAction(MainWindow);
        actionExport_Character_Sheet->setObjectName(QStringLiteral("actionExport_Character_Sheet"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        abilityGroup = new QGroupBox(centralWidget);
        abilityGroup->setObjectName(QStringLiteral("abilityGroup"));
        abilityGroup->setGeometry(QRect(12, 72, 172, 168));
        strLabel = new QLabel(abilityGroup);
        strLabel->setObjectName(QStringLiteral("strLabel"));
        strLabel->setGeometry(QRect(16, 24, 72, 16));
        QFont font;
        font.setPointSize(10);
        strLabel->setFont(font);
        dexLabel = new QLabel(abilityGroup);
        dexLabel->setObjectName(QStringLiteral("dexLabel"));
        dexLabel->setGeometry(QRect(16, 48, 72, 16));
        dexLabel->setFont(font);
        conLabel = new QLabel(abilityGroup);
        conLabel->setObjectName(QStringLiteral("conLabel"));
        conLabel->setGeometry(QRect(16, 72, 72, 16));
        conLabel->setFont(font);
        intLabel = new QLabel(abilityGroup);
        intLabel->setObjectName(QStringLiteral("intLabel"));
        intLabel->setGeometry(QRect(16, 96, 72, 16));
        intLabel->setFont(font);
        wisLabel = new QLabel(abilityGroup);
        wisLabel->setObjectName(QStringLiteral("wisLabel"));
        wisLabel->setGeometry(QRect(16, 120, 72, 16));
        wisLabel->setFont(font);
        chaLabel = new QLabel(abilityGroup);
        chaLabel->setObjectName(QStringLiteral("chaLabel"));
        chaLabel->setGeometry(QRect(16, 144, 72, 16));
        chaLabel->setFont(font);
        strVal = new QLabel(abilityGroup);
        strVal->setObjectName(QStringLiteral("strVal"));
        strVal->setGeometry(QRect(96, 24, 16, 16));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        strVal->setFont(font1);
        strVal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dexVal = new QLabel(abilityGroup);
        dexVal->setObjectName(QStringLiteral("dexVal"));
        dexVal->setGeometry(QRect(96, 48, 16, 16));
        dexVal->setFont(font1);
        dexVal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        conVal = new QLabel(abilityGroup);
        conVal->setObjectName(QStringLiteral("conVal"));
        conVal->setGeometry(QRect(96, 72, 16, 16));
        conVal->setFont(font1);
        conVal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        intVal = new QLabel(abilityGroup);
        intVal->setObjectName(QStringLiteral("intVal"));
        intVal->setGeometry(QRect(96, 96, 16, 16));
        intVal->setFont(font1);
        intVal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        wisVal = new QLabel(abilityGroup);
        wisVal->setObjectName(QStringLiteral("wisVal"));
        wisVal->setGeometry(QRect(96, 120, 16, 16));
        wisVal->setFont(font1);
        wisVal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        chaVal = new QLabel(abilityGroup);
        chaVal->setObjectName(QStringLiteral("chaVal"));
        chaVal->setGeometry(QRect(96, 144, 16, 16));
        chaVal->setFont(font1);
        chaVal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        abilityEdit = new QPushButton(abilityGroup);
        abilityEdit->setObjectName(QStringLiteral("abilityEdit"));
        abilityEdit->setEnabled(false);
        abilityEdit->setGeometry(QRect(128, 12, 36, 24));
        skillsGroup = new QGroupBox(centralWidget);
        skillsGroup->setObjectName(QStringLiteral("skillsGroup"));
        skillsGroup->setGeometry(QRect(188, 72, 230, 168));
        skillsList = new QListWidget(skillsGroup);
        skillsList->setObjectName(QStringLiteral("skillsList"));
        skillsList->setGeometry(QRect(10, 20, 171, 121));
        skillsAdd = new QPushButton(skillsGroup);
        skillsAdd->setObjectName(QStringLiteral("skillsAdd"));
        skillsAdd->setEnabled(false);
        skillsAdd->setGeometry(QRect(186, 12, 32, 24));
        unspentSkillsLabel = new QLabel(skillsGroup);
        unspentSkillsLabel->setObjectName(QStringLiteral("unspentSkillsLabel"));
        unspentSkillsLabel->setGeometry(QRect(12, 144, 121, 16));
        skillsRemove = new QPushButton(skillsGroup);
        skillsRemove->setObjectName(QStringLiteral("skillsRemove"));
        skillsRemove->setEnabled(false);
        skillsRemove->setGeometry(QRect(186, 40, 32, 24));
        featsGroup = new QGroupBox(centralWidget);
        featsGroup->setObjectName(QStringLiteral("featsGroup"));
        featsGroup->setGeometry(QRect(422, 72, 230, 82));
        featsList = new QListWidget(featsGroup);
        featsList->setObjectName(QStringLiteral("featsList"));
        featsList->setGeometry(QRect(12, 16, 171, 41));
        featsAdd = new QPushButton(featsGroup);
        featsAdd->setObjectName(QStringLiteral("featsAdd"));
        featsAdd->setEnabled(false);
        featsAdd->setGeometry(QRect(186, 12, 32, 24));
        unspentFeatsLabel = new QLabel(featsGroup);
        unspentFeatsLabel->setObjectName(QStringLiteral("unspentFeatsLabel"));
        unspentFeatsLabel->setGeometry(QRect(12, 61, 121, 16));
        featsRemove = new QPushButton(featsGroup);
        featsRemove->setObjectName(QStringLiteral("featsRemove"));
        featsRemove->setEnabled(false);
        featsRemove->setGeometry(QRect(186, 40, 32, 24));
        generalGroup = new QGroupBox(centralWidget);
        generalGroup->setObjectName(QStringLiteral("generalGroup"));
        generalGroup->setGeometry(QRect(12, 12, 640, 61));
        horizontalLayoutWidget = new QWidget(generalGroup);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 621, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(horizontalLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(nameLabel);

        nameEdit = new QLineEdit(horizontalLayoutWidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setEnabled(false);

        horizontalLayout->addWidget(nameEdit);

        alignLabel = new QLabel(horizontalLayoutWidget);
        alignLabel->setObjectName(QStringLiteral("alignLabel"));
        alignLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(alignLabel);

        alignSelect = new QComboBox(horizontalLayoutWidget);
        alignSelect->setObjectName(QStringLiteral("alignSelect"));
        alignSelect->setEnabled(false);

        horizontalLayout->addWidget(alignSelect);

        raceLabel = new QLabel(horizontalLayoutWidget);
        raceLabel->setObjectName(QStringLiteral("raceLabel"));
        raceLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(raceLabel);

        raceSelect = new QComboBox(horizontalLayoutWidget);
        raceSelect->setObjectName(QStringLiteral("raceSelect"));
        raceSelect->setEnabled(false);

        horizontalLayout->addWidget(raceSelect);

        genderLabel = new QLabel(horizontalLayoutWidget);
        genderLabel->setObjectName(QStringLiteral("genderLabel"));
        genderLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(genderLabel);

        genderSelect = new QComboBox(horizontalLayoutWidget);
        genderSelect->setObjectName(QStringLiteral("genderSelect"));
        genderSelect->setEnabled(false);

        horizontalLayout->addWidget(genderSelect);

        wizardGroup = new QGroupBox(centralWidget);
        wizardGroup->setObjectName(QStringLiteral("wizardGroup"));
        wizardGroup->setEnabled(true);
        wizardGroup->setGeometry(QRect(422, 158, 230, 152));
        schoolSelect = new QComboBox(wizardGroup);
        schoolSelect->setObjectName(QStringLiteral("schoolSelect"));
        schoolSelect->setGeometry(QRect(124, 20, 96, 22));
        schoolLabel = new QLabel(wizardGroup);
        schoolLabel->setObjectName(QStringLiteral("schoolLabel"));
        schoolLabel->setGeometry(QRect(16, 24, 81, 16));
        spellbookList = new QListWidget(wizardGroup);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(spellbookList);
        __qlistwidgetitem->setCheckState(Qt::Unchecked);
        __qlistwidgetitem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(spellbookList);
        __qlistwidgetitem1->setCheckState(Qt::Unchecked);
        __qlistwidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(spellbookList);
        __qlistwidgetitem2->setCheckState(Qt::Unchecked);
        __qlistwidgetitem2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(spellbookList);
        __qlistwidgetitem3->setCheckState(Qt::Unchecked);
        __qlistwidgetitem3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(spellbookList);
        __qlistwidgetitem4->setCheckState(Qt::Unchecked);
        __qlistwidgetitem4->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(spellbookList);
        __qlistwidgetitem5->setCheckState(Qt::Unchecked);
        __qlistwidgetitem5->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(spellbookList);
        __qlistwidgetitem6->setCheckState(Qt::Unchecked);
        __qlistwidgetitem6->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem7 = new QListWidgetItem(spellbookList);
        __qlistwidgetitem7->setCheckState(Qt::Unchecked);
        __qlistwidgetitem7->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem8 = new QListWidgetItem(spellbookList);
        __qlistwidgetitem8->setCheckState(Qt::Unchecked);
        __qlistwidgetitem8->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem9 = new QListWidgetItem(spellbookList);
        __qlistwidgetitem9->setCheckState(Qt::Unchecked);
        __qlistwidgetitem9->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        spellbookList->setObjectName(QStringLiteral("spellbookList"));
        spellbookList->setGeometry(QRect(70, 50, 151, 91));
        spellbookLabel = new QLabel(wizardGroup);
        spellbookLabel->setObjectName(QStringLiteral("spellbookLabel"));
        spellbookLabel->setGeometry(QRect(16, 48, 47, 13));
        fighterGroup = new QGroupBox(centralWidget);
        fighterGroup->setObjectName(QStringLiteral("fighterGroup"));
        fighterGroup->setGeometry(QRect(422, 158, 230, 64));
        weaponFocusLabel = new QLabel(fighterGroup);
        weaponFocusLabel->setObjectName(QStringLiteral("weaponFocusLabel"));
        weaponFocusLabel->setGeometry(QRect(16, 24, 81, 16));
        weaponFocusSelect = new QComboBox(fighterGroup);
        weaponFocusSelect->setObjectName(QStringLiteral("weaponFocusSelect"));
        weaponFocusSelect->setGeometry(QRect(124, 20, 96, 22));
        rogueGroup = new QGroupBox(centralWidget);
        rogueGroup->setObjectName(QStringLiteral("rogueGroup"));
        rogueGroup->setGeometry(QRect(422, 158, 230, 64));
        rogueLabel = new QLabel(rogueGroup);
        rogueLabel->setObjectName(QStringLiteral("rogueLabel"));
        rogueLabel->setGeometry(QRect(16, 24, 161, 16));
        clericGroup = new QGroupBox(centralWidget);
        clericGroup->setObjectName(QStringLiteral("clericGroup"));
        clericGroup->setGeometry(QRect(422, 158, 230, 64));
        godSelect = new QComboBox(clericGroup);
        godSelect->setObjectName(QStringLiteral("godSelect"));
        godSelect->setGeometry(QRect(124, 20, 96, 22));
        godLabel = new QLabel(clericGroup);
        godLabel->setObjectName(QStringLiteral("godLabel"));
        godLabel->setGeometry(QRect(16, 24, 71, 16));
        equipmentGroup = new QGroupBox(centralWidget);
        equipmentGroup->setObjectName(QStringLiteral("equipmentGroup"));
        equipmentGroup->setGeometry(QRect(12, 244, 406, 111));
        moneyLabel = new QLabel(equipmentGroup);
        moneyLabel->setObjectName(QStringLiteral("moneyLabel"));
        moneyLabel->setGeometry(QRect(12, 16, 47, 13));
        gpValLabel = new QLabel(equipmentGroup);
        gpValLabel->setObjectName(QStringLiteral("gpValLabel"));
        gpValLabel->setGeometry(QRect(16, 32, 24, 16));
        gpValLabel->setFont(font);
        gpValLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spValLabel = new QLabel(equipmentGroup);
        spValLabel->setObjectName(QStringLiteral("spValLabel"));
        spValLabel->setGeometry(QRect(16, 56, 24, 16));
        spValLabel->setFont(font);
        spValLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cpValLabel = new QLabel(equipmentGroup);
        cpValLabel->setObjectName(QStringLiteral("cpValLabel"));
        cpValLabel->setGeometry(QRect(16, 80, 24, 16));
        cpValLabel->setFont(font);
        cpValLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        gpLabel = new QLabel(equipmentGroup);
        gpLabel->setObjectName(QStringLiteral("gpLabel"));
        gpLabel->setGeometry(QRect(48, 32, 92, 16));
        gpLabel->setFont(font);
        spLabel = new QLabel(equipmentGroup);
        spLabel->setObjectName(QStringLiteral("spLabel"));
        spLabel->setGeometry(QRect(48, 56, 92, 16));
        spLabel->setFont(font);
        cpLabel = new QLabel(equipmentGroup);
        cpLabel->setObjectName(QStringLiteral("cpLabel"));
        cpLabel->setGeometry(QRect(48, 80, 92, 16));
        cpLabel->setFont(font);
        equipRemove = new QPushButton(equipmentGroup);
        equipRemove->setObjectName(QStringLiteral("equipRemove"));
        equipRemove->setEnabled(false);
        equipRemove->setGeometry(QRect(362, 40, 32, 24));
        listWidget = new QListWidget(equipmentGroup);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(144, 12, 211, 91));
        equipAdd = new QPushButton(equipmentGroup);
        equipAdd->setObjectName(QStringLiteral("equipAdd"));
        equipAdd->setEnabled(false);
        equipAdd->setGeometry(QRect(362, 12, 32, 24));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 664, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew_Character);
        menuFile->addAction(actionOpen_Character);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExport_Character_Sheet);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);
        QObject::connect(actionNew_Character, SIGNAL(triggered()), MainWindow, SLOT(newCharacter()));
        QObject::connect(alignSelect, SIGNAL(currentIndexChanged(int)), MainWindow, SLOT(editAlignment(int)));
        QObject::connect(nameEdit, SIGNAL(textEdited(QString)), MainWindow, SLOT(editName(QString)));
        QObject::connect(raceSelect, SIGNAL(currentIndexChanged(int)), MainWindow, SLOT(editRace(int)));
        QObject::connect(abilityEdit, SIGNAL(clicked()), MainWindow, SLOT(openAbilityEditor()));

        alignSelect->setCurrentIndex(-1);
        raceSelect->setCurrentIndex(-1);
        genderSelect->setCurrentIndex(-1);
        weaponFocusSelect->setCurrentIndex(2);
        godSelect->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionNew_Character->setText(QApplication::translate("MainWindow", "New Character...", Q_NULLPTR));
        actionOpen_Character->setText(QApplication::translate("MainWindow", "Open Character...", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", Q_NULLPTR));
        actionExport_Character_Sheet->setText(QApplication::translate("MainWindow", "Export Character Sheet", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        abilityGroup->setTitle(QApplication::translate("MainWindow", "Ability Scores", Q_NULLPTR));
        strLabel->setText(QApplication::translate("MainWindow", "Strength", Q_NULLPTR));
        dexLabel->setText(QApplication::translate("MainWindow", "Dexterity", Q_NULLPTR));
        conLabel->setText(QApplication::translate("MainWindow", "Constitution", Q_NULLPTR));
        intLabel->setText(QApplication::translate("MainWindow", "Intelligence", Q_NULLPTR));
        wisLabel->setText(QApplication::translate("MainWindow", "Wisdom", Q_NULLPTR));
        chaLabel->setText(QApplication::translate("MainWindow", "Charisma", Q_NULLPTR));
        strVal->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        dexVal->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        conVal->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        intVal->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        wisVal->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        chaVal->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        abilityEdit->setText(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        skillsGroup->setTitle(QApplication::translate("MainWindow", "Trained Skills", Q_NULLPTR));
        skillsAdd->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        unspentSkillsLabel->setText(QApplication::translate("MainWindow", "0 skill ranks remaining.", Q_NULLPTR));
        skillsRemove->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        featsGroup->setTitle(QApplication::translate("MainWindow", "Feats", Q_NULLPTR));
        featsAdd->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        unspentFeatsLabel->setText(QApplication::translate("MainWindow", "0 skill ranks remaining.", Q_NULLPTR));
        featsRemove->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        generalGroup->setTitle(QApplication::translate("MainWindow", "General Information", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("MainWindow", "Character Name", Q_NULLPTR));
        nameEdit->setText(QString());
        alignLabel->setText(QApplication::translate("MainWindow", "Alignment", Q_NULLPTR));
        alignSelect->clear();
        alignSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Lawful Good", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Neutral Good", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Chaotic Good", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Lawful Neutral", Q_NULLPTR)
         << QApplication::translate("MainWindow", "True Neutral", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Chaotic Neutral", Q_NULLPTR)
        );
        raceLabel->setText(QApplication::translate("MainWindow", "Race", Q_NULLPTR));
        raceSelect->clear();
        raceSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Human", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Elf", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Dwarf", Q_NULLPTR)
        );
        genderLabel->setText(QApplication::translate("MainWindow", "Gender", Q_NULLPTR));
        genderSelect->clear();
        genderSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Male", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Female", Q_NULLPTR)
        );
        wizardGroup->setTitle(QApplication::translate("MainWindow", "Wizard Options", Q_NULLPTR));
        schoolSelect->clear();
        schoolSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Universalist", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Evocation", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Illusion", Q_NULLPTR)
        );
        schoolLabel->setText(QApplication::translate("MainWindow", "Arcane School", Q_NULLPTR));

        const bool __sortingEnabled = spellbookList->isSortingEnabled();
        spellbookList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = spellbookList->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Alarm", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = spellbookList->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "Burning Hands", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = spellbookList->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "Cause Fear", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem3 = spellbookList->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "Charm Person", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem4 = spellbookList->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MainWindow", "Detect Secret Doors", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem5 = spellbookList->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("MainWindow", "Disguise Self", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem6 = spellbookList->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("MainWindow", "Feather Fall", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem7 = spellbookList->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("MainWindow", "Mage Armor", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem8 = spellbookList->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("MainWindow", "Magic Missile", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem9 = spellbookList->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("MainWindow", "Sleep", Q_NULLPTR));
        spellbookList->setSortingEnabled(__sortingEnabled);

        spellbookLabel->setText(QApplication::translate("MainWindow", "Spellbook", Q_NULLPTR));
        fighterGroup->setTitle(QApplication::translate("MainWindow", "Fighter Options", Q_NULLPTR));
        weaponFocusLabel->setText(QApplication::translate("MainWindow", "Weapon Focus", Q_NULLPTR));
        weaponFocusSelect->clear();
        weaponFocusSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Battleaxe", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Longsword", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Warhammer", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Shortbow", Q_NULLPTR)
        );
        rogueGroup->setTitle(QApplication::translate("MainWindow", "Rogue Options", Q_NULLPTR));
        rogueLabel->setText(QApplication::translate("MainWindow", "Rogues have no special options.", Q_NULLPTR));
        clericGroup->setTitle(QApplication::translate("MainWindow", "Cleric Options", Q_NULLPTR));
        godSelect->clear();
        godSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Desna", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Gorum", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Sarenrae", Q_NULLPTR)
        );
        godLabel->setText(QApplication::translate("MainWindow", "Patron God", Q_NULLPTR));
        equipmentGroup->setTitle(QApplication::translate("MainWindow", "Equipment", Q_NULLPTR));
        moneyLabel->setText(QApplication::translate("MainWindow", "Money", Q_NULLPTR));
        gpValLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        spValLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        cpValLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        gpLabel->setText(QApplication::translate("MainWindow", "gold pieces", Q_NULLPTR));
        spLabel->setText(QApplication::translate("MainWindow", "silver pieces", Q_NULLPTR));
        cpLabel->setText(QApplication::translate("MainWindow", "copper pieces", Q_NULLPTR));
        equipRemove->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        equipAdd->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
