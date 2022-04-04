#include "CVBoard.hpp"

void CVBoard::find_board()
{
    cv::Mat img = cv::imread( filename_, -1);

    if(img.empty())
    {
        std::cout << "Could not find file" << std::endl;
        return;
    }

    cv::namedWindow( "Example 2-1", cv::WINDOW_AUTOSIZE );
    cv::imshow( "Example 2-1", img );
    cv::waitKey( 0 );
    cv::destroyWindow( "Example 2-1" );

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