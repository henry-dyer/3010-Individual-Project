#ifndef _GEN_BOARD_H_
#define _GEN_BOARD_H_

#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <sstream>
#include "Board.h"

enum class Difficulty{EASY = 1, MEDIUM, HARD};

class GenBoard : public Board
{   
    public:
        GenBoard(Difficulty difficulty);
        void show_solution();

    private:
        Difficulty difficulty_;
        std::string filename_;
};

#endif
