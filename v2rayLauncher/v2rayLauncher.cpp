#include "v2rayLauncher.h"

v2rayLauncher::v2rayLauncher(QWidget *parent)
	: QMainWindow(parent),
	ui(new Ui::v2rayLauncherClass)
{
	systemTray = new QSystemTrayIcon(this);
	menu = new QMenu(this);
	action_about = new QAction(menu);
	action_start = new QAction(menu);
	action_stop = new QAction(menu);
	action_restart = new QAction(menu);
	action_quit = new QAction(menu);

	action_about->setText("About");
	action_about->setIcon(QIcon(":/v2rayLauncher/Resources/hj.png"));
	action_start->setText("Start");
	action_start->setIcon(QIcon(":/v2rayLauncher/Resources/hj.png"));
	action_stop->setText("Stop");
	action_stop->setIcon(QIcon(":/v2rayLauncher/Resources/hj.png"));
	action_restart->setText("Restart");
	action_restart->setIcon(QIcon(":/v2rayLauncher/Resources/hj.png"));
	action_quit->setText("Quit");
	action_quit->setIcon(QIcon(":/v2rayLauncher/Resources/hj.png"));

	action_stop->setDisabled(true);
	action_restart->setDisabled(true);
	
	menu->addAction(action_about);
	menu->addSeparator();
	menu->addAction(action_start);
	menu->addAction(action_stop);
	menu->addAction(action_restart);
	menu->addSeparator();
	menu->addAction(action_quit);
	menu->setDefaultAction(action_about);

	connect(action_about,SIGNAL(triggered(bool)), this, SLOT(showAbout()));
	connect(action_start, SIGNAL(triggered(bool)), this, SLOT(startServer()));
	connect(action_stop, SIGNAL(triggered(bool)), this, SLOT(stopServer()));
	connect(action_restart, SIGNAL(triggered(bool)), this, SLOT(restartServer()));
	connect(action_quit, SIGNAL(triggered(bool)), this, SLOT(quitApp()));

	systemTray->setContextMenu(menu);
	systemTray->setIcon(QIcon(":/v2rayLauncher/Resources/icon.png"));
	systemTray->setToolTip("v2ray Launcher");
	systemTray->show();
	connect(systemTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
		this, SLOT(trayiconActivated(QSystemTrayIcon::ActivationReason)));

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	ui->setupUi(this);
}

void v2rayLauncher::showAbout()
{
	About *about = new About(this);
	about->show();
}

void v2rayLauncher::startServer()
{
	if (!CreateProcess(TEXT(".\\wv2ray.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		QMessageBox::critical(this, "Error", QString(int(GetLastError())), QMessageBox::Ok);
	}
	else
	{
		action_start->setDisabled(true);
		action_stop->setDisabled(false);
		action_restart->setEnabled(true);
	}
}

void v2rayLauncher::stopServer()
{
	if (TerminateProcess(pi.hProcess, 0))
	{
		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);
		ZeroMemory(&pi, sizeof(pi));
		action_start->setDisabled(false);
		action_stop->setDisabled(true);
		action_restart->setEnabled(true);
	}
	else
	{
		QMessageBox::critical(this, "Error", QString(int(GetLastError())), QMessageBox::Ok);
	}
}

void v2rayLauncher::restartServer()
{
	stopServer();
	startServer();
}

void v2rayLauncher::quitApp()
{
	QApplication::quit();
}

void v2rayLauncher::showMenu()
{
	menu->popup(QCursor::pos());
}

void v2rayLauncher::trayiconActivated(QSystemTrayIcon::ActivationReason reason)
{
	if (reason == QSystemTrayIcon::Trigger)
	{
		showMenu();
	}
}
