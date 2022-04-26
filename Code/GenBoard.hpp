#ifndef _GEN_BOARD_HPP_
#define _GEN_BOARD_HPP_

#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <sstream>
#include "Board.hpp"

enum class Difficulty{EASY = 1, MEDIUM, HARD};

class GenBoard : public Board
{   
    public:
        GenBoard();

    private:
        Difficulty difficulty_;
        std::string filename_;
};

#endif