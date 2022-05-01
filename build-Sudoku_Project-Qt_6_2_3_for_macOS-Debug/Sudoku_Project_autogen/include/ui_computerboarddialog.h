/********************************************************************************
** Form generated from reading UI file 'computerboarddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPUTERBOARDDIALOG_H
#define UI_COMPUTERBOARDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComputerBoardDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *easyButton;
    QPushButton *mediumButton;
    QPushButton *hardButton;

    void setupUi(QDialog *ComputerBoardDialog)
    {
        if (ComputerBoardDialog->objectName().isEmpty())
            ComputerBoardDialog->setObjectName(QString::fromUtf8("ComputerBoardDialog"));
        ComputerBoardDialog->resize(400, 300);
        verticalLayoutWidget = new QWidget(ComputerBoardDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(110, 100, 160, 86));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        easyButton = new QPushButton(verticalLayoutWidget);
        easyButton->setObjectName(QString::fromUtf8("easyButton"));

        verticalLayout->addWidget(easyButton);

        mediumButton = new QPushButton(verticalLayoutWidget);
        mediumButton->setObjectName(QString::fromUtf8("mediumButton"));

        verticalLayout->addWidget(mediumButton);

        hardButton = new QPushButton(verticalLayoutWidget);
        hardButton->setObjectName(QString::fromUtf8("hardButton"));

        verticalLayout->addWidget(hardButton);


        retranslateUi(ComputerBoardDialog);

        QMetaObject::connectSlotsByName(ComputerBoardDialog);
    } // setupUi

    void retranslateUi(QDialog *ComputerBoardDialog)
    {
        ComputerBoardDialog->setWindowTitle(QCoreApplication::translate("ComputerBoardDialog", "Dialog", nullptr));
        easyButton->setText(QCoreApplication::translate("ComputerBoardDialog", "Easy", nullptr));
        mediumButton->setText(QCoreApplication::translate("ComputerBoardDialog", "Intermediate", nullptr));
        hardButton->setText(QCoreApplication::translate("ComputerBoardDialog", "Hard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComputerBoardDialog: public Ui_ComputerBoardDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPUTERBOARDDIALOG_H
