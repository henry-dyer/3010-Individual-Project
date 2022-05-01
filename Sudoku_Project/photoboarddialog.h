#ifndef PHOTOBOARDDIALOG_H
#define PHOTOBOARDDIALOG_H

#include <QDialog>

namespace Ui {
class PhotoBoardDialog;
}

class PhotoBoardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PhotoBoardDialog(QWidget *parent = nullptr);
    std::string get_filename(){return filename_;};
    ~PhotoBoardDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PhotoBoardDialog *ui;
    std::string filename_;
};

#endif // PHOTOBOARDDIALOG_H
