/********************************************************************************
** Form generated from reading UI file 'gameoptiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOPTIONDIALOG_H
#define UI_GAMEOPTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GameOptionDialog
{
public:
    QPushButton *uploadButton;
    QPushButton *generateButton;

    void setupUi(QDialog *GameOptionDialog)
    {
        if (GameOptionDialog->objectName().isEmpty())
            GameOptionDialog->setObjectName(QString::fromUtf8("GameOptionDialog"));
        GameOptionDialog->resize(400, 300);
        uploadButton = new QPushButton(GameOptionDialog);
        uploadButton->setObjectName(QString::fromUtf8("uploadButton"));
        uploadButton->setGeometry(QRect(80, 130, 101, 24));
        generateButton = new QPushButton(GameOptionDialog);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        generateButton->setGeometry(QRect(200, 130, 111, 24));

        retranslateUi(GameOptionDialog);

        QMetaObject::connectSlotsByName(GameOptionDialog);
    } // setupUi

    void retranslateUi(QDialog *GameOptionDialog)
    {
        GameOptionDialog->setWindowTitle(QCoreApplication::translate("GameOptionDialog", "Dialog", nullptr));
        uploadButton->setText(QCoreApplication::translate("GameOptionDialog", "Upload Photo", nullptr));
        generateButton->setText(QCoreApplication::translate("GameOptionDialog", "Generate Board", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameOptionDialog: public Ui_GameOptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOPTIONDIALOG_H
