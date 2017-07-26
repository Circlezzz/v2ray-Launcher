#pragma once

#include <QtWidgets/QMainWindow>
#include <qsystemtrayicon.h>
#include "ui_v2rayLauncher.h"
#include "About.h"
#include <Windows.h>
#include <qmessagebox.h>
#include "qtimer.h"
#include "qapplication.h"
#include <TlHelp32.h>
#include "qdesktopwidget.h"

class v2rayLauncher : public QMainWindow
{
	Q_OBJECT

public:
	v2rayLauncher(QWidget *parent = Q_NULLPTR);

private:
	Ui::v2rayLauncherClass *ui;
	QSystemTrayIcon *systemTray;
	QMenu *menu;
	QAction *action_about;
	QAction *action_start;
	QAction *action_stop;
	QAction *action_restart;
	QAction *action_quit;

	QDesktopWidget *desktop = QApplication::desktop();

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	bool isStart = false;

	private slots:
	void showAbout();
	void startServer();
	void stopServer();
	void restartServer();
	void quitApp();
	void showMenu();
	void trayiconActivated(QSystemTrayIcon::ActivationReason reason);
	bool ProcessIsCreated();
};
