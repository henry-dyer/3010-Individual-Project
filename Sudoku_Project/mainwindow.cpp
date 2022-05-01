#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <fstream>

using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    god = new GameOptionDialog();
    god->setModal(true);
    god->exec();


    if(god->get_gameOption())
    {
        if(check_filename(god->get_filename()))
        {
            board_ = new GenBoard(Difficulty::EASY);
        }
        else
        {
            //Should add pop up saying filename was not valid
            qDebug() << "Invalid File";
            this->close();
        }
    }
    else
    {
        board_ = new GenBoard(god->get_difficulty());
    }

    board_->solve_board();

    QGraphicsView *view = ui->graphicsView;

    scene = new QGraphicsScene;

    view->setScene(scene);
    view->setSceneRect(0,0, view->frameSize().width(), view->frameSize().height());

    for(int i = 0 ; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            scene->addItem(board_->get_square(i, j));
            connect(board_->get_square(i, j), &Square::SquareSelected, this, &MainWindow::SquareSelected);
        }
     }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete board_;
}

bool MainWindow::check_filename(std::string filename)
{

    std::string filename2 = ":/" + filename;

   // qDebug() << QString::fromStdString(filename2);

    cv::Mat img = imread( filename, cv::IMREAD_GRAYSCALE);

    //if(img.empty())
    //{
    //   return false;
    //}

    namedWindow( "Sudoku Solution", WINDOW_AUTOSIZE );
    imshow( "Sudoku Solution", img);

    //Destroys window and terminates program when any key is pressed
    waitKey( 0 );
    destroyAllWindows( );

    return true;
}


void MainWindow::on_hintButton_clicked()
{
    board_->give_hint();
    scene->update();
}

void MainWindow::on_solutionButton_clicked()
{
    board_->show_solution();
    scene->update();
}

void MainWindow::SquareSelected(Square* curr)
{
    curr_ = curr;
    scene->update();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(curr_ == NULL || curr_->get_prefilled()) return;

    qDebug() << "At location : " << curr_->get_x() << " , " << curr_->get_y();

    if(board_->get_solution( curr_->get_x() , curr_->get_y()) == event->key() - 48)
    {
        curr_->set_isValid(true);
    }
    else
    {
        curr_->set_isValid(false);
    }

    switch(event->key())
    {
        case Qt::Key_1:
            curr_->set_value(1);
            break;
         case Qt::Key_2:
            curr_->set_value(2);
            break;
        case Qt::Key_3:
           curr_->set_value(3);
           break;
        case Qt::Key_4:
           curr_->set_value(4);
           break;
        case Qt::Key_5:
           curr_->set_value(5);
           break;
        case Qt::Key_6:
           curr_->set_value(6);
           break;
        case Qt::Key_7:
           curr_->set_value(7);
           break;
        case Qt::Key_8:
           curr_->set_value(8);
           break;
        case Qt::Key_9:
           curr_->set_value(9);
           break;
        default:
           break;
    }
    scene->update();
}

