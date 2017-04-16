/********************************************************************************
** Form generated from reading UI file 'welcomewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEWINDOW_H
#define UI_WELCOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WelcomeWindow
{
public:
    QPushButton *newCharButton;
    QPushButton *openCharButton;
    QPushButton *quitButton;

    void setupUi(QDialog *WelcomeWindow)
    {
        if (WelcomeWindow->objectName().isEmpty())
            WelcomeWindow->setObjectName(QStringLiteral("WelcomeWindow"));
        WelcomeWindow->setWindowModality(Qt::ApplicationModal);
        WelcomeWindow->resize(288, 160);
        newCharButton = new QPushButton(WelcomeWindow);
        newCharButton->setObjectName(QStringLiteral("newCharButton"));
        newCharButton->setGeometry(QRect(16, 16, 256, 32));
        openCharButton = new QPushButton(WelcomeWindow);
        openCharButton->setObjectName(QStringLiteral("openCharButton"));
        openCharButton->setGeometry(QRect(16, 64, 256, 32));
        quitButton = new QPushButton(WelcomeWindow);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(16, 112, 256, 32));

        retranslateUi(WelcomeWindow);
        QObject::connect(newCharButton, SIGNAL(clicked()), WelcomeWindow, SLOT(chooseNew()));
        QObject::connect(openCharButton, SIGNAL(clicked()), WelcomeWindow, SLOT(chooseOpen()));
        QObject::connect(quitButton, SIGNAL(clicked()), WelcomeWindow, SLOT(chooseQuit()));

        QMetaObject::connectSlotsByName(WelcomeWindow);
    } // setupUi

    void retranslateUi(QDialog *WelcomeWindow)
    {
        WelcomeWindow->setWindowTitle(QApplication::translate("WelcomeWindow", "Welcome to Gamestork", Q_NULLPTR));
        newCharButton->setText(QApplication::translate("WelcomeWindow", "Create a new character", Q_NULLPTR));
        openCharButton->setText(QApplication::translate("WelcomeWindow", "Open an existing character", Q_NULLPTR));
        quitButton->setText(QApplication::translate("WelcomeWindow", "Quit Gamestork", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WelcomeWindow: public Ui_WelcomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEWINDOW_H
