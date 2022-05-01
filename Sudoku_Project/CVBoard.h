#ifndef _CV_BOARD_H_
#define _CV_BOARD_H_

#include "Board.h"
#include <string>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include <opencv2/core.hpp>
#include <tesseract/baseapi.h>
#include <allheaders.h>
#include <vector>

class CVBoard : public Board
{
    public:

        CVBoard(std::string filename);
        void draw_solution();
        
    private:
        std::string filename_;
        int original_[9][9];
        int cornerX_;
        int cornerY_;
        int boardWidth_;
        int boardHeight_;
};

#endif
