#include "board.hpp"

Board::Board()
{
    for (int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            _board_[i][j] = Square();
            _solution_[i][j] = 0;
        }
    }
    _hints_ = 0;
}

Board::Board(int setup[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            _board_[i][j] = Square(setup[i][j]);

            _solution_[i][j] = setup[i][j];
        }
    }
}

const Square Board::get_square(int xCoor, int yCoor)
{
    return _board_[xCoor][yCoor];
}


void Board::print_board()
{
    std::cout << "     1 2 3   4 5 6   7 8 9" << std::endl << std::endl;

    for(int i = 0; i < 9; i++)
    {
        std::cout << char(65+i) << "    ";
        for(int j = 0; j < 9; j++)
        {
            std::cout << _board_[i][j].get_value() << " ";

            if(j == 2 || j == 5) std::cout << "| "; 
        }
        std::cout << std::endl;

        if(i == 2 || i == 5)
        {
            std::cout << "     ---------------------" << std::endl;
        }
    }
    std::cout << std::endl;

    return;
}


void Board::give_hint()
{

}

bool valid_row()
{

}

bool valid_column()
{

}

bool valid_box()
{

}

bool Board::solve_board()
{

}


/*
std::ostream& operator<<(std::ostream& os, const Board &mb)
{
    std::cout << "     1 2 3   4 5 6   7 8 9" << std::endl << std::endl;

    for(int i = 0; i < 9; i++)
    {
        os << char(65+i) << "    ";
        for(int j = 0; j < 9; j++)
        {
            os << b.get_square(i, j).get_value() << " ";

            if(j == 2 || j == 5) os << "| "; 
        }
        os << std::endl;

        if(i == 2 || i == 5)
        {
            os << "     ---------------------" << std::endl;
        }
    }
    os << std::endl;

    return os;
}

*/