#include "CVBoard.hpp"

#include "opencv2/imgcodecs.hpp"

using namespace cv;

bool compareContourAreas( std::vector<cv::Point> contour1, std::vector<cv::Point> contour2 ) {
    double i = fabs( contourArea(cv::Mat(contour1)) );
    double j = fabs( contourArea(cv::Mat(contour2)) );
    return ( i < j );
}

int crop_index(Point a, Point b)
{
    int width = b.x - a.x;
    int height = b.y - a.y;

    return width * height;
}

Mat preprocess(Mat image)
{
    Mat dst, output;
    Canny(image, dst, 50, 200, 3);
    cvtColor(dst, output, COLOR_GRAY2BGR);

    return output;
}

void CVBoard::find_board()
{
    Mat img, dst, cdst;

    //reads in image file
    img = imread( filename_, IMREAD_GRAYSCALE);

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();

    ocr->SetPageSegMode(tesseract::PSM_AUTO);

    if (api->Init(NULL, "eng")) {
        std::cout << "Could not initialize Tesseract." << std::endl;
        return;
    }
    
    //Checks to see if image file is empty
    if(img.empty())
    {
        std::cout << "Could not open image." << std::endl;
        return;
    }

    //Preprocessing image to help with edge detection
    Canny(img, dst, 50, 200, 3);
    cvtColor(dst, cdst, COLOR_GRAY2BGR);

    // Detects lines using HoughLinesP method
    std::vector<Vec2f> lines; 
    std::vector<Vec4i> linesP; 
    HoughLinesP(dst, linesP, 1, CV_PI/180, 50, 50, 10 ); 

    Vec4i hLine = {10000, 10000, 10000, 10000};
    Vec4i vLine = {10000, 10000, 10000, 10000};

    //Finds a vertical and horizontal edge line 
    for( size_t i = 0; i < linesP.size(); i++ )
    {
        Vec4i l = linesP[i];
        //line( cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, LINE_AA);
        if(l[1] == l[3] && l[1] < hLine[1])
        {
            hLine = l;
        }

        if(l[0] == l[2] && l[1] < vLine[1])
        {
            vLine = l;
        }
    }
    //Draws rectangle around the outside of the image
    //rectangle( cdst, Point(vLine[0], vLine[1]), Point(hLine[2], hLine[3]), Scalar(255, 0, 0), 3, LINE_AA);



    Mat crop = cdst(Range(hLine[0], hLine[2]), Range(vLine[3], vLine[1]));

    int width = (crop.size().width / 9);
    int height = (crop.size().height / 9);

    //std::cout << "Upper Corner : " << width * 0 << " , " << height * 0 << " , lower corner : " << width * 1 << " , " << height * 1 << std::endl;

    std::string outText;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            //std::cout << "Upper Corner : " << width * j << " , " << height * i << " , lower corner : " << width * (j + 1) << " , " << height * (i + 1) << std::endl;
            rectangle(crop, Point(width * j, height* i), Point(width * (j + 1), height* (i + 1)), Scalar(0, 0, 255), 1, LINE_AA);
            cell = crop(Range((width * j, height* i), Range(width * (j + 1), height* (i + 1));
            ocr->SetImage(cell, cell.size().width, cell.size().height, 3, cell.step);
            outText = std::string(ocr->GetUTF8Text());
            std::cout << i << " , " << j << " : " << outText << std::endl;
        }
        width = (crop.size().width / 9);
    }

    //Mat cell = crop(Range(0))
    

    //std::cout << "Width : " << width << std::endl;
    //std::cout << "Height : " << height << std::endl;

    //Displays image
    namedWindow( "Image", WINDOW_AUTOSIZE );
    imshow( "Image", crop);

    //Destroys window and terminates program when any key is pressed
    waitKey( 0 );
    destroyWindow( "Image" );

    return;
}

/*
    Takes user input for the filename they wish to enter
    Only allows for .png or .jpg files
    @param NONE
    @return NONE
*/
void CVBoard::input_filename()
{
    std::string filename;
    while(1)
    {
        std::cout << "Please enter the filename for the photo you wish to upload: ";
        std::cin >> filename;

        if(filename.substr(filename.length() - 4, 4) == ".png" || filename.substr(filename.length() - 4, 4) == ".jpg") break;

        std::cout << "Please enter a .png or .jpg file" << std::endl;
    }
    filename_ = filename;
    return;
}