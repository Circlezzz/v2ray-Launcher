#include "v2rayLauncher.h"
#include <QtWidgets/QApplication>
#include <QtPlugin>
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setQuitOnLastWindowClosed(false);
	v2rayLauncher w;
	//w.show();
	w.hide();
	return a.exec();
}
