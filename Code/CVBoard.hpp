#ifndef _CV_BOARD_HPP_
#define _CV_BOARD_HPP_

#include "Board.hpp"
#include "string"
#include <opencv2/opencv.hpp>

class CVBoard : public Board
{
    public:

        CVBoard() : Board() {};
        void find_board();
        void input_filename();

    private:
        std::string filename_;
};

#endif