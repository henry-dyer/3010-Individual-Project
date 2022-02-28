#ifndef _BOARD_HPP_
#define _BOARD_HPP_

#include "square.hpp"
#include <iostream>

class Board
{
    public:
        Board();
        Board(int setup[9][9]);

        const Square get_square(int xCoor, int yCoor);

        void give_hint();

        void print_board();

        bool solve_board();

        friend std::ostream& operator<<(std::ostream& os, const Board &b);

    private:
        Square _board_[9][9];
        int _solution_[9][9];
        int _hints_;
};

#endif