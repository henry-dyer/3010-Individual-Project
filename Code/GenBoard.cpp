#include "GenBoard.hpp"

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
    std::string filename = "../Sudoku_Boards/";
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
GenBoard::GenBoard()
{
    difficulty_ = get_difficulty();
    filename_ = get_filename(difficulty_);
    
    std::string file_line;
    std::ifstream boardFile(filename_);

    int row = 0;
    while(getline(boardFile, file_line))
    {
        std::stringstream ss(file_line);
        int col = 0;
        while(ss.good())
        {
            std::string substr;
            getline(ss, substr, ',');

            _board_[row][col] = Square(stoi(substr));
            _solution_[row][col] = stoi(substr);

            col++;
        }
        row++;
    }
}
        