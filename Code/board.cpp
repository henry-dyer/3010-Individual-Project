#include "Board.hpp"

/*
Things to fix:
Board << overload function
Inputting a non number in as input

Note: prefilled function will always return true when until solve board method is implemented.

//give hint function has comment that might need to be addressed
*/

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

Board::Board(std::vector<std::vector<int>> setup)
{
    for (int i = 0; i < setup.size(); i++)
    {
        for(int j = 0; j < setup[i].size(); j++)
        {
            _board_[i][j] = Square(setup[i][j]);

            _solution_[i][j] = setup[i][j];
        }
    }
}


//Should be const methods 
Square Board::get_square(int xCoor, int yCoor)
{
    return _board_[xCoor][yCoor];
}

/*
    Takes user input for the board coordinate they want to change, will 
    not let them change spots pre determined by initial board.
    @param NONE
    @return a Coordinate Struct containing the x and y coordinatess
*/
Coordinate Board::get_user_move()
{
    int xCoor = 0;
    int yCoor = 0;

    while(1)
    {
        while(1)
        {
            std::cout << "Please enter a column selection (1 - 9): ";
            std::cin >> yCoor;
            if(!std::cin.fail() && yCoor > 0 && yCoor < 10) break;
            std::cout << "Invalid input please try again\n";
        }

        while(1)
        {
            std::cout << "Please enter a row selection (1 - 9): ";
            std::cin >> xCoor;
            if(!std::cin.fail() && xCoor > 0 && xCoor < 10) break;
            std::cout << "Invalid input please try again\n";
        }
        if(prefilled(xCoor - 1, yCoor -1))
        {
            std::cout << "(" << yCoor << " , " << xCoor << ") is a prefilled spot, please select a spot." << std:: endl;
        }
        else break;
    }

    //Need to simplify this
    Coordinate coor;
    coor.xCoor_ = xCoor;
    coor.yCoor_ = yCoor;
    return coor;
}

/*
    Takes a coordinate from the get_user_move() function and then takes a value
    to put in the spot, will not allow for wrong moves here 
    @param NONE
    @return NONE
*/
void Board::execute_move()
{
    Coordinate coordinate = get_user_move();
    int val;

    std::cout << "Updating spot : " << coordinate.yCoor_ << " , " << coordinate.xCoor_ << std::endl;
    
    while(1)
    {
        std::cout << "Please enter a the value for this spot: ";
        std::cin >> val;
        if(!std::cin.fail() && val > 0 && val < 10)
        {
            if(valid_move(coordinate, val)) break;
            else std::cout << "Incorrect move." << std::endl;
        } 
        else std::cout << "Invalid input please try again\n";
    }
    _board_[coordinate.xCoor_ - 1][coordinate.yCoor_ -1].set_value(val);
    return;
}

bool Board::valid_move(Coordinate coordinate, int val)
{
    if(_solution_[coordinate.xCoor_ - 1][coordinate.yCoor_ -1] == val) return true;
    return false;
}


void Board::print_board()
{
    std::cout << "     1 2 3   4 5 6   7 8 9" << std::endl << std::endl;

    for(int i = 0; i < 9; i++)
    {
        std::cout << (i + 1) << "    ";
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

void Board::print_solution()
{
    std::cout << "     1 2 3   4 5 6   7 8 9" << std::endl << std::endl;

    for(int i = 0; i < 9; i++)
    {
        std::cout << (i + 1) << "    ";
        for(int j = 0; j < 9; j++)
        {
            std::cout << _solution_[i][j]<< " ";

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

/*
    Checke if location passed as parameters was a spot given by the original board.
    @param X and Y coordinates of spot to check
    @return True if spot was prefilled by computer, if not false
*/
bool Board::prefilled(int xCoor, int yCoor)
{
    if(_board_[xCoor][yCoor].get_prefilled()) return true;
    return false;
}

/*
    Loops through finding a random spot on the board and checking if the spot has been filled in yet.
    Once it finds an unfilled spot it put the correct value from the solution in the spot
    @param NONE
    @return NONE
*/
void Board::give_hint()
{
    int randRow;
    int randCol;

    _hints_++;

    while(1)
    {
        srand(time(NULL));

        randRow = rand() % 9;
        randCol = rand() % 9;

        if(_board_[randRow][randCol].get_value()) // not sure if this works for ints as well as bools
        {
            continue;
        }
        else
        {
            _board_[randRow][randCol] = _solution_[randRow][randCol];
        }
    }
    return;
}

/*
    Checks if move is valid at specified row, helper function for valid_spot method
    @param Coordinate location to check
    @param Int value to check
    @return Valid / Not Valid
*/
bool valid_row(int board[9][9], Coordinate coordinate, int val)
{
    for(int i = 0; i < 9; i++)
    {
        if(board[i][coordinate.yCoor_] == val) return false;
    }
    return true;
}

/*
    Checks if move is valid at specified column, helper function for valid_spot method
    @param Coordinate location to check
    @param Int value to check
    @return Valid / Not Valid
*/
bool valid_column(int board[9][9], Coordinate coordinate, int val)
{
    for(int i = 0; i < 9; i++)
    {
        if(board[coordinate.xCoor_][i] == val) return false;
    }
    return true;
}


/*
    Checks if move is valid at specified box, helper function for valid_spot method
    @param Coordinate location to check
    @param Int value to check
    @return Valid / Not Valid
*/
bool valid_box(int board[9][9], Coordinate coordinate, int val)
{
    int xBox = ((coordinate.xCoor_) / 3) * 3;
    int yBox = ((coordinate.yCoor_)/ 3) * 3;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[xBox + i][yBox + j] == val) return false;
        }
    }
    return true;
}

bool Board::valid_spot(Coordinate coordinate, int val)
{
    return valid_row(_solution_, coordinate, val) && valid_column(_solution_, coordinate, val) && valid_box(_solution_, coordinate, val);
}

/*
    Helper function for the solve_board() method to find the next empty spot.
    @param Int Array with same dimensions as board to iterate over
    @return a Coordinate struct with location of next empty spot, returns (-1, -1) if no spots available
*/
Coordinate solve_spot(int board[9][9])
{
    Coordinate coordinate;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] == 0)
            {
                coordinate.xCoor_ = i;
                coordinate.yCoor_ = j;
                return coordinate;
            }
        }
    }
    coordinate.xCoor_ = -1;
    coordinate.yCoor_ = -1;
    return coordinate;
}

bool Board::solve_board()
{
    Coordinate current = solve_spot(_solution_);

    if(current.xCoor_ == -1) return true;

    for(int i = 1; i <= 9; i++)
    {
        if(valid_spot(current, i))
        {
            _solution_[current.xCoor_][current.yCoor_] = i;
            if(solve_board()) return true;
            _solution_[current.xCoor_][current.yCoor_] = 0;
        }
    }
    return false;
}   

int Board::get_solution(int xCoor, int yCoor)
{
    return _solution_[xCoor][yCoor];
}

bool Board::game_over()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(_board_[i][j].get_value() != _solution_[i][j]) return false;
        }
    }
    return true;
}

/*
std::ostream& operator<<(std::ostream& os, const Board &b)
{
    std::cout << "     1 2 3   4 5 6   7 8 9" << std::endl << std::endl;

    for(int i = 0; i < 9; i++)
    {
        os << i << "    ";
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

