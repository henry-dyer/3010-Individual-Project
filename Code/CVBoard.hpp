#ifndef _CV_BOARD_HPP_
#define _CV_BOARD_HPP_

#include "Board.hpp"
#include "string"
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include <opencv2/core.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <vector>

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