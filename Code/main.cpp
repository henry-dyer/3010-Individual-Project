#include "Board.hpp"
#include "GenBoard.hpp"
#include "CVBoard.hpp"

#include <iostream>

int board_options();
bool play_game(Board board);

int main()
{
    std::string filename;

    std::cout << "Welcome to Sudoku, please select one of the following options" << std::endl;
    int choice = board_options();

    if(choice == 1)
    {
        CVBoard cv_board;

        cv_board.solve_board();

        cv_board.draw_solution();

        play_game(cv_board);

        

    }
    else
    {
        GenBoard gen_board;
        play_game(gen_board);
    }
    return 0;
}

/*
Lets user select whether to upload file or play game created by CPU
@param NONE
@return 1 - Upload Photo , 2 - CPU Board
*/
int board_options()
{
    std::string choice = "0";
    while(choice != "1" || choice != "2")
    {  
        std::cout << "1. Upload a photo of a sudoku game." << std::endl;
        std::cout << "2. Start a new game." << std::endl;

        std::cin >> choice;

        if(choice == "1" || choice == "2") return stoi(choice);

        std::cout << "Invalid option selected, please try again." << std::endl; 
    }   
    return -1;
}

/*
    Allows user to play sudoku game
    @param Board object
    @return T/F whether game was completed successfully.
*/
bool play_game(Board board)
{
    if(!board.solve_board())
    {
        std::cout << "Board could not be solved" << std::endl;
        return false;
    }

    while(!board.game_over())
    {
        board.print_board();
        board.execute_move();
    }
    return true;
}