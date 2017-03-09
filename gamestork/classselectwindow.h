#pragma once

#include <QWindow>
//#include "ui_classselectwindow.h"

namespace Ui {
	class ClassSelectWindow;
}

class ClassSelectWindow : public QWindow, public ClassSelectWindow
{
	Q_OBJECT

public:
	ClassSelectWindow(QWidget *parent = Q_NULLPTR);
	~ClassSelectWindow();
};
