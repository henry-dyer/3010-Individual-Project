#include "gameoptiondialog.h"
#include "ui_gameoptiondialog.h"

GameOptionDialog::GameOptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOptionDialog)
{
    ui->setupUi(this);
}

GameOptionDialog::~GameOptionDialog()
{
    delete ui;
}

void GameOptionDialog::on_uploadButton_clicked()
{
    gameOption_ = true;

    this->close();

    pbd = new PhotoBoardDialog();
    pbd->setModal(true);
    pbd->exec();
    filename_ = pbd->get_filename();
}

void GameOptionDialog::on_generateButton_clicked()
{
    gameOption_ = false;

    this->close();

    cbd = new ComputerBoardDialog();
    cbd->setModal(true);
    cbd->exec();
    difficulty_ = cbd->get_difficulty();
}

