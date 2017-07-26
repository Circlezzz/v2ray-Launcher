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
	systemTray->setToolTip("v2ray Launcher [Stopped]");
	systemTray->show();
	connect(systemTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
		this, SLOT(trayiconActivated(QSystemTrayIcon::ActivationReason)));

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	ui->setupUi(this);

	if (ProcessIsCreated())
	{
		QMessageBox::critical(this, "Error", "Another wv2ray.exe or v2ray.exe is running.", QMessageBox::Ok);
		QTimer::singleShot(0, qApp, SLOT(quit()));
	}
	else {
		startServer();
	}
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
		isStart = false;
		QMessageBox::critical(this, "Error", QString("Error code: ")+QString::number(GetLastError(),10)+QString("\nCannot find wv2ray.exe in current directory, please check out. "), QMessageBox::Ok);
	}
	else
	{
		action_start->setDisabled(true);
		action_stop->setDisabled(false);
		action_restart->setEnabled(true);
		isStart = true;
		systemTray->setToolTip("v2ray Launcher [Started]");
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
		action_restart->setEnabled(false);
		isStart = false;
		systemTray->setToolTip("v2ray Launcher [Stopped]");
	}
	else
	{
		isStart = true;
		QMessageBox::critical(this, "Error", QString("Error code: ") + QString::number(GetLastError(), 10) + QString("\nError occurred while closing the wv2ray.exe"), QMessageBox::Ok);
	}
}

void v2rayLauncher::restartServer()
{
	stopServer();
	startServer();
}

void v2rayLauncher::quitApp()
{
	if (isStart)
	{
		stopServer();
	}
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

bool v2rayLauncher::ProcessIsCreated()
{
	PROCESSENTRY32 pe32;
	ZeroMemory(&pe32, sizeof(pe32));
	pe32.dwSize = sizeof(pe32);
	TCHAR processName[15] = TEXT("wv2ray.exe");
	TCHAR processName2[15] = TEXT("v2ray.exe");
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		return true;
	}
	bool bMore = Process32First(hProcessSnap, &pe32);
	while (bMore)
	{
		if (wcscmp(processName, pe32.szExeFile)==0|| wcscmp(processName2, pe32.szExeFile) == 0)
		{
			return true;
		}
		bMore = Process32Next(hProcessSnap, &pe32);
	}
	return false;
}
