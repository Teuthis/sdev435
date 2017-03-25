/********************************************************************************
** Form generated from reading UI file 'featchooserwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEATCHOOSERWINDOW_H
#define UI_FEATCHOOSERWINDOW_H

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

class Ui_FeatChooserWindow
{
public:
    QLabel *headingLabel;
    QListWidget *featsList;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *FeatChooserWindow)
    {
        if (FeatChooserWindow->objectName().isEmpty())
            FeatChooserWindow->setObjectName(QStringLiteral("FeatChooserWindow"));
        FeatChooserWindow->resize(196, 210);
        headingLabel = new QLabel(FeatChooserWindow);
        headingLabel->setObjectName(QStringLiteral("headingLabel"));
        headingLabel->setGeometry(QRect(12, 12, 72, 13));
        featsList = new QListWidget(FeatChooserWindow);
        featsList->setObjectName(QStringLiteral("featsList"));
        featsList->setGeometry(QRect(12, 32, 172, 144));
        cancelButton = new QPushButton(FeatChooserWindow);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(109, 180, 75, 23));
        okButton = new QPushButton(FeatChooserWindow);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(30, 180, 75, 23));

        retranslateUi(FeatChooserWindow);
        QObject::connect(cancelButton, SIGNAL(clicked()), FeatChooserWindow, SLOT(close()));
        QObject::connect(okButton, SIGNAL(clicked()), FeatChooserWindow, SLOT(featChosen()));

        QMetaObject::connectSlotsByName(FeatChooserWindow);
    } // setupUi

    void retranslateUi(QDialog *FeatChooserWindow)
    {
        FeatChooserWindow->setWindowTitle(QApplication::translate("FeatChooserWindow", "FeatChooserWindow", Q_NULLPTR));
        headingLabel->setText(QApplication::translate("FeatChooserWindow", "Available feats:", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("FeatChooserWindow", "Cancel", Q_NULLPTR));
        okButton->setText(QApplication::translate("FeatChooserWindow", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FeatChooserWindow: public Ui_FeatChooserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEATCHOOSERWINDOW_H
