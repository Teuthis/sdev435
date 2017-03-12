/********************************************************************************
** Form generated from reading UI file 'equipmentchooserwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUIPMENTCHOOSERWINDOW_H
#define UI_EQUIPMENTCHOOSERWINDOW_H

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

class Ui_EquipmentChooserWindow
{
public:
    QLabel *headingLabel;
    QListWidget *itemList;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *EquipmentChooserWindow)
    {
        if (EquipmentChooserWindow->objectName().isEmpty())
            EquipmentChooserWindow->setObjectName(QStringLiteral("EquipmentChooserWindow"));
        EquipmentChooserWindow->setWindowModality(Qt::ApplicationModal);
        EquipmentChooserWindow->resize(287, 274);
        headingLabel = new QLabel(EquipmentChooserWindow);
        headingLabel->setObjectName(QStringLiteral("headingLabel"));
        headingLabel->setGeometry(QRect(12, 12, 128, 13));
        itemList = new QListWidget(EquipmentChooserWindow);
        itemList->setObjectName(QStringLiteral("itemList"));
        itemList->setGeometry(QRect(12, 32, 256, 192));
        cancelButton = new QPushButton(EquipmentChooserWindow);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(190, 240, 75, 23));
        okButton = new QPushButton(EquipmentChooserWindow);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(100, 240, 75, 23));

        retranslateUi(EquipmentChooserWindow);
        QObject::connect(cancelButton, SIGNAL(clicked()), EquipmentChooserWindow, SLOT(close()));
        QObject::connect(okButton, SIGNAL(clicked()), EquipmentChooserWindow, SLOT(itemSelected()));

        QMetaObject::connectSlotsByName(EquipmentChooserWindow);
    } // setupUi

    void retranslateUi(QDialog *EquipmentChooserWindow)
    {
        EquipmentChooserWindow->setWindowTitle(QApplication::translate("EquipmentChooserWindow", "EquipmentChooserWindow", Q_NULLPTR));
        headingLabel->setText(QApplication::translate("EquipmentChooserWindow", "Choose item to purchase:", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("EquipmentChooserWindow", "Cancel", Q_NULLPTR));
        okButton->setText(QApplication::translate("EquipmentChooserWindow", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EquipmentChooserWindow: public Ui_EquipmentChooserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUIPMENTCHOOSERWINDOW_H
