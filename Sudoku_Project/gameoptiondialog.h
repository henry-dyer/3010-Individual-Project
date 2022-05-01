#ifndef GAMEOPTIONDIALOG_H
#define GAMEOPTIONDIALOG_H

#include <QDialog>
#include "photoboarddialog.h"
#include "computerboarddialog.h"
#include "GenBoard.h"

namespace Ui {
class GameOptionDialog;
}

class GameOptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameOptionDialog(QWidget *parent = nullptr);
    Difficulty get_difficulty() { return difficulty_ ; };
    std::string get_filename() { return filename_ ; };
    bool get_gameOption() { return gameOption_; };

    ~GameOptionDialog();

private slots:
    void on_uploadButton_clicked();

    void on_generateButton_clicked();

private:
    Ui::GameOptionDialog *ui;
    PhotoBoardDialog* pbd;
    ComputerBoardDialog* cbd;
    bool gameOption_; //True represents uploading a photo and false represents computer generating a board
    Difficulty difficulty_;
    std::string filename_;
};

#endif // GAMEOPTIONDIALOG_H
