#ifndef _GEN_BOARD_HPP_
#define _GEN_BOARD_HPP_

#include "Board.hpp"


enum class Difficulty{EASY = 1, MEDIUM, HARD};

class GenBoard : public Board
{   
    public:
        GenBoard(int setup[9][9]) : Board(setup) {};
        


    private:
        Difficulty difficulty;
        std::string filename_;
};


#endif