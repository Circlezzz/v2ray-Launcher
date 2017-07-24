/********************************************************************************
** Form generated from reading UI file 'v2rayLauncher.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V2RAYLAUNCHER_H
#define UI_V2RAYLAUNCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_v2rayLauncherClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *v2rayLauncherClass)
    {
        if (v2rayLauncherClass->objectName().isEmpty())
            v2rayLauncherClass->setObjectName(QStringLiteral("v2rayLauncherClass"));
        v2rayLauncherClass->setEnabled(true);
        v2rayLauncherClass->resize(94, 57);
        v2rayLauncherClass->setAnimated(false);
        centralWidget = new QWidget(v2rayLauncherClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        v2rayLauncherClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(v2rayLauncherClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 94, 21));
        v2rayLauncherClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(v2rayLauncherClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        v2rayLauncherClass->setStatusBar(statusBar);

        retranslateUi(v2rayLauncherClass);

        QMetaObject::connectSlotsByName(v2rayLauncherClass);
    } // setupUi

    void retranslateUi(QMainWindow *v2rayLauncherClass)
    {
        v2rayLauncherClass->setWindowTitle(QApplication::translate("v2rayLauncherClass", "v2rayLauncher", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class v2rayLauncherClass: public Ui_v2rayLauncherClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V2RAYLAUNCHER_H
