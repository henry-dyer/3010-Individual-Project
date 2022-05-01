/********************************************************************************
** Form generated from reading UI file 'photoboarddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHOTOBOARDDIALOG_H
#define UI_PHOTOBOARDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhotoBoardDialog
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *PhotoBoardDialog)
    {
        if (PhotoBoardDialog->objectName().isEmpty())
            PhotoBoardDialog->setObjectName(QString::fromUtf8("PhotoBoardDialog"));
        PhotoBoardDialog->resize(400, 300);
        horizontalLayoutWidget = new QWidget(PhotoBoardDialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(80, 130, 211, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(horizontalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout->addWidget(textEdit);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(PhotoBoardDialog);

        QMetaObject::connectSlotsByName(PhotoBoardDialog);
    } // setupUi

    void retranslateUi(QDialog *PhotoBoardDialog)
    {
        PhotoBoardDialog->setWindowTitle(QCoreApplication::translate("PhotoBoardDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("PhotoBoardDialog", "Load", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PhotoBoardDialog: public Ui_PhotoBoardDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOBOARDDIALOG_H
