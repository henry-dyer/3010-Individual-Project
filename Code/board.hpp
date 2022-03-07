#ifndef _BOARD_HPP_
#define _BOARD_HPP_

#include "Square.hpp"
#include <iostream>

class Board
{
    public:
        Board();
        Board(int setup[9][9]);

        const Square get_square(int xCoor, int yCoor);

        void give_hint();

        void user_move();

        void print_board();

        bool valid_move();

        bool solve_board();

        bool empty_spot(int xCoor, int yCoor);

        friend std::ostream& operator<<(std::ostream& os, const Board &b);

    private:
        Square _board_[9][9];
        int _solution_[9][9];
        int _hints_;
};

#endif