#ifndef _CV_BOARD_HPP_
#define _CV_BOARD_HPP_

#include "board.hpp"
#include "string"
//#include </Users/henrydyer/Documents/OpenCV/installation/OpenCV/lib/cmake/opencv4/opencv.hpp>

class CVBoard : public Board
{
    public:
        void find_board();

        const string get_filename();
        void set_filename(string filname);

    private:
        string _filename_;
};

#endif