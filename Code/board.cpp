#include "Board.hpp"

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

void Board::user_move()
{
    int xCoor = 0;
    int yCoor = 0;
    bool emptySpot = false;

    while(!emptySpot)
    {
        while(xCoor < 1 && xCoor > 9)
        {
            std::cout << "Please enter a row selection (1 - 9): ";
            std::cin >> xCoor;
            if(!cin.fail()) continue;
            std::cout << "Invalid input please try again\n" 
        }

        while(yCoor < 1 && yCoor > 9)
        {
            std::cout << "Please enter a row selection (1 - 9): ";
            std::cin >> yCoor;
            if(!cin.fail()) continue;
            std::cout << "Invalid input please try again\n" 
        }
        emptySpot = empty_spot(xCoor, yCoor);
    }

}


void Board::print_board()
{
    std::cout << "     1 2 3   4 5 6   7 8 9" << std::endl << std::endl;

    for(int i = 0; i < 9; i++)
    {
        std::cout << i << "    ";
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

bool Board::empty_spot(int xCoor, int yCoor)
{
    if(_board_[xCoor][yCoor] == 0) return true;

    return false;
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

bool Board::valid_move()
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