#include "GenBoard.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>

/*
    Takes user input for difficulty level of board they would like to play
    @param NONE
    @return Difficulty ENUM 
*/
Difficulty get_difficulty()
{
    std::string difficulty = "";

    while(1)
    {
        std::cout << "Select a difficulty level: " << std::endl;
        std::cout << "1. Easy, 2. Medium. 3. Hard" << std::endl;
        std::cin >> difficulty;

        if(difficulty == "1" || difficulty == "2" || difficulty == "3") break;
        else 
        {
            std::cout << "Invalid option selected, please enter 1, 2, or 3." << std::endl;
        }
    }
    return static_cast<Difficulty>(stoi(difficulty));
}

/*
Selects a random text file containing contents to load sudoku board
@param Difficulty level
@return string containing path to text file
*/
std::string get_filename(Difficulty difficulty)
{
    std::string filename = ":/Sudoku_Boards/";
    std::string file_number;
    int randFile;

    switch(difficulty)
    {
        case Difficulty::EASY:
            filename += "easy_";
            break;
        case Difficulty::MEDIUM:
            filename += "medium_";
            break;
        case Difficulty::HARD:
            filename += "hard_";
        default:
            std::cout << "Invalid Parameter\n";
    }

    srand(time(NULL));

    randFile = rand() % 3 + 1;
    file_number = std::to_string(randFile);

    filename += file_number + ".txt";
    return filename;
}

/*
    GenBoard Constructors which reads in txt file and turns it into playable sudoku board
    @param NONE
    @return NONE
*/
GenBoard::GenBoard(Difficulty difficulty)
{
    difficulty_ = difficulty;
    filename_ = get_filename(difficulty);
    
    QFile file(QString::fromStdString(filename_));

    if (file.open(QIODevice::ReadOnly))
    {
        int row = 0;
        QTextStream input(&file);
        QStringList values;
        while(!input.atEnd())
        {
            QString line = input.readLine();
            values = line.split(",");

           // qDebug() << values;

            for(int col = 0; col < 9; col ++)
            {
                //qDebug() << values[col][0].digitValue();
                _board_[row][col] = new Square(values[col][0].digitValue(), col , row);
                _solution_[row][col] = values[col][0].digitValue();
            }
            row++;
        }
    }
    else
    {
        qDebug() << "Could not open file";
    }
}

void GenBoard::show_solution()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            _board_[i][j]->set_value(_solution_[i][j]);
        }
    }
    return;
}
        
