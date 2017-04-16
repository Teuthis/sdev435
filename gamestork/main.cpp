//-----------------------------------------------------------------------------
/**
File: main.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Application entry point. Launches MainWindow
*/
//-----------------------------------------------------------------------------

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

	
    w.show();

    return a.exec();
}
