#ifndef _CV_BOARD_HPP_
#define _CV_BOARD_HPP_

#include "Board.hpp"
#include "string"
//#include </Users/henrydyer/Documents/OpenCV/installation/OpenCV/lib/cmake/opencv4/opencv.hpp>

class CVBoard : public Board
{
    public:

        //CVBoard() : Board();
        void find_board();

        const std::string get_filename() {return filename_;};
        void set_filename(std::string filname) ;

    private:
        std::string filename_;
};

#endif