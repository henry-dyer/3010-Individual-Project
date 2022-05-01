#include "computerboarddialog.h"
#include "ui_computerboarddialog.h"

ComputerBoardDialog::ComputerBoardDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputerBoardDialog)
{
    ui->setupUi(this);
}

ComputerBoardDialog::~ComputerBoardDialog()
{
    delete ui;
}

void ComputerBoardDialog::on_easyButton_clicked()
{
    difficulty_ = Difficulty::EASY;
    this->close();
}


void ComputerBoardDialog::on_mediumButton_clicked()
{
    difficulty_ = Difficulty::MEDIUM;
    this->close();
}


void ComputerBoardDialog::on_hardButton_clicked()
{
    difficulty_ = Difficulty::HARD;
    this->close();
}

