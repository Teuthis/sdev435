#include "featchooserwindow.h"

FeatChooserWindow::FeatChooserWindow(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}

FeatChooserWindow::~FeatChooserWindow()
{
}

void FeatChooserWindow::featChosen() 
{
	if (featsList->currentRow() != -1) {
		emit featAdded(*(featsList->currentItem()));
	}
}