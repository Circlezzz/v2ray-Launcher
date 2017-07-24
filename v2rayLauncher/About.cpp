#include "About.h"

About::About(QWidget *parent)
	: QDialog(parent)
{
	this->setAttribute(Qt::WA_DeleteOnClose, true);
	ui.setupUi(this);
}

About::~About()
{
	this->close();
}
