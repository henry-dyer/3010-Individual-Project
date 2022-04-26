#include "CVBoard.hpp"
#include "opencv2/imgcodecs.hpp"

using namespace cv;

/*
    Takes user input for the filename they wish to enter
    Only allows for .png or .jpg files
    @param NONE
    @return NONE
*/
std::string input_filename()
{
    std::string filename;
    while(1)
    {
        std::cout << "Please enter the filename for the photo you wish to upload: ";
        std::cin >> filename;

        if(filename.substr(filename.length() - 4, 4) == ".png" || filename.substr(filename.length() - 4, 4) == ".jpg") break;

        std::cout << "Please enter a .png or .jpg file" << std::endl;
    }
    return filename;
}

/*
    Helper function which extracts character from image passed as parameter
    @param Pix*
    @return Char* of extracted text
*/
char* extract_value(Pix* img)
{
    tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();
    char* outText;

    ocr->SetPageSegMode(tesseract::PSM_AUTO);
    ocr->Init(NULL, "eng", tesseract::OEM_DEFAULT);
    
    if (ocr->Init(NULL, "eng")) {
        std::cout << "Could not initialize Tesseract." << std::endl;
        return outText;
    }

    ocr->SetImage(img);
    ocr->SetVariable("classify_bln_numeric_mode", "1"); 

    outText = ocr->GetUTF8Text();

    ocr->End();
    delete ocr;

    return outText;
}


CVBoard::CVBoard()
{
    filename_ = input_filename();

    Mat img, dst, cdst;

    //reads in image file
    img = imread( filename_, IMREAD_GRAYSCALE);

    //Checks to see if image file is empty
    if(img.empty())
    {
        std::cout << "Could not open image." << std::endl;
        exit(-1);
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
        if(l[1] == l[3] && l[1] < hLine[1])
        {
            hLine = l;
        }
        if(l[0] == l[2] && l[1] < vLine[1])
        {
            vLine = l;
        }
    }

    cornerX_ = hLine[0];
    cornerY_ = vLine[3];

    //Crops the image around the corners found from the horizontal and vertical lines above.
    Mat crop = img(Range(hLine[0], hLine[2]), Range(vLine[3], vLine[1])).clone();

    //These values might be different since the board is cropped might have to set them before the board gets cropped
    boardWidth_ = crop.size().width;
    boardHeight_ = crop.size().height;

    float width = crop.cols / 9.0;
    float height = crop.rows / 9.0;

    Mat cell;
    char* outText;
    int num;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            
            //rectangle(crop, Point_<float>((width * j) + 9, (height * i) + 9), Point_<float>((width * (j + 1)) - 9, (height* (i + 1)) - 9), Scalar(0, 0, 255), 1, LINE_AA);
            cell = crop(Rect( (width * j) + 8 , (height * i) + 8 , width - 10, height - 10 )).clone();
            
            imwrite("../Code/cell.jpg",cell);
            Pix *image = pixRead("cell.jpg");

            outText = extract_value(image);
            cell.release();

            num = outText[0] - 48;

            if(num >= 0 && num < 10)
            {
                _board_[i][j] = Square(num);
                _solution_[i][j] = num;
                original_[i][j] = num;
            }
            else {
                _board_[i][j] = Square(0);
                _solution_[i][j] = 0;
                original_[i][j] = 0;
            } 
        }
    }
}

void CVBoard::draw_solution()
{
    std::string value;

    Mat img = imread( filename_, IMREAD_COLOR);

    float width = boardWidth_ / 9.0;
    float height = boardHeight_ / 9.0;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(original_[i][j] == 0)
            {
                value = std::to_string(_solution_[i][j]); 
                //Adjust + 10 values to ideally center the 
                putText(img, value, cv::Point(cornerX_ + (width * j) + 25, cornerY_ + (height * i) + 48), cv::FONT_HERSHEY_SIMPLEX, 1.6, CV_RGB(0, 0, 255), 2, FILLED);
            }
        }
    }

    //Displays image
    namedWindow( "Sudoku Solution", WINDOW_AUTOSIZE );
    imshow( "Sudoku Solution", img);

    //Destroys window and terminates program when any key is pressed
    waitKey( 0 );
    destroyAllWindows( );

    return;
}

