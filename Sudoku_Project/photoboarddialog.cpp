#include "photoboarddialog.h"
#include "ui_photoboarddialog.h"

PhotoBoardDialog::PhotoBoardDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PhotoBoardDialog)
{
    ui->setupUi(this);
}

PhotoBoardDialog::~PhotoBoardDialog()
{
    delete ui;
}

void PhotoBoardDialog::on_pushButton_clicked()
{
    this->close();
    filename_ = ui->textEdit->toPlainText().toStdString();
}

