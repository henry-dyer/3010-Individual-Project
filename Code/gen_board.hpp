#ifndef _GEN_BOARD_HPP_
#define _GET_BOARD_HPP_

#include "board.hpp"

enum class Difficulty{EASY, MEDIUM, HARD};

class GenBoard : public Board
{   
    public:

    private:
        Difficulty difficulty;
};


#endif