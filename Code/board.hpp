#ifndef _BOARD_HPP_
#define _BOARD_HPP_

#include "Square.hpp"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>


struct Coordinate
{
    int xCoor_;
    int yCoor_;
};

class Board
{
    public:
        Board();
        Board(int setup[9][9]);
        Board(std::vector<std::vector<int>> setup);

        Square get_square(int xCoor, int yCoor);

        void give_hint();

        Coordinate get_user_move();

        void execute_move();

        void print_board();

        void print_solution();

        bool valid_move(Coordinate coordinate, int val);

        bool valid_spot(Coordinate coordinate, int val);

        bool solve_board();

        bool game_over();

        bool prefilled(int xCoor, int yCoor);

        int get_solution(int xCoor, int yCoor);

        friend std::ostream& operator<<(std::ostream& os, const Board &b);

    protected:
        Square _board_[9][9];
        int _solution_[9][9];
        int _hints_;
};

#endif