/********************************************************************************
** Form generated from reading UI file 'About.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QStringLiteral("About"));
        About->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/v2rayLauncher/Resources/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        About->setWindowIcon(icon);
        label = new QLabel(About);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 221, 221));
        label->setPixmap(QPixmap(QString::fromUtf8(":/v2rayLauncher/Resources/picture.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(About);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 30, 111, 16));
        label_3 = new QLabel(About);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(280, 60, 61, 16));
        label_4 = new QLabel(About);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(270, 110, 81, 16));

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "About", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("About", "v2ray Launcher V1.0", Q_NULLPTR));
        label_3->setText(QApplication::translate("About", "2017.7.24", Q_NULLPTR));
        label_4->setText(QApplication::translate("About", "<html><head/><body><p><a href=\"https://github.com/v2ray/v2ray-core\"><span style=\" color:#0000ff;\">v2ray - github</span></a></p></body></html>", Q_NULLPTR));
		label_4->setOpenExternalLinks(true);
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
