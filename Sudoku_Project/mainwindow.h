#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QGraphicsScene>
#include "gameoptiondialog.h"
#include "photoboarddialog.h"
#include "computerboarddialog.h"
#include "Board.h"
#include "CVBoard.h"
#include "GenBoard.h"
#include "opencv2/imgcodecs.hpp"
#include <QKeyEvent>
#include <Qt>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bool check_filename(std::string filename);
    ~MainWindow();

private slots:
    void on_hintButton_clicked();
    void on_solutionButton_clicked();
    void SquareSelected(Square* curr);

protected:
    void keyPressEvent(QKeyEvent* event) override;

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    GameOptionDialog* god;
    Board* board_;
    CVBoard* cvboard_;
    GenBoard* genboard_;
    Square* curr_;

};
#endif // MAINWINDOW_H
