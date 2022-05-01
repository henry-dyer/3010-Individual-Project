#ifndef COMPUTERBOARDDIALOG_H
#define COMPUTERBOARDDIALOG_H

#include <QDialog>
#include "GenBoard.h"

namespace Ui {
class ComputerBoardDialog;
}

class ComputerBoardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ComputerBoardDialog(QWidget *parent = nullptr);
    Difficulty get_difficulty() {return difficulty_;};
    ~ComputerBoardDialog();

private slots:
    void on_easyButton_clicked();
    void on_mediumButton_clicked();
    void on_hardButton_clicked();

private:
    Ui::ComputerBoardDialog *ui;
    Difficulty difficulty_;
};

#endif // COMPUTERBOARDDIALOG_H
