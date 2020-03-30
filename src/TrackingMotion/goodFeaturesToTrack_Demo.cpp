/**
 * @function goodFeaturesToTrack_Demo.cpp
 * @brief Demo code for detecting corners using Shi-Tomasi method
 * @author OpenCV team
 */

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>


/// Global variables
cv::Mat src, src_gray;

int maxCorners = 23;
int maxTrackbar = 100;

cv::RNG rng(12345);
const char* source_window = "Image";

/**
 * @function goodFeaturesToTrack_Demo.cpp
 * @brief Apply Shi-Tomasi corner detector
 */
void goodFeaturesToTrack_Demo( int, void* )
{
    /// Parameters for Shi-Tomasi algorithm
    maxCorners = MAX(maxCorners, 1);
    std::vector<cv::Point2f> corners;
    double qualityLevel = 0.01;
    double minDistance = 10;
    int blockSize = 3, gradientSize = 3;
    bool useHarrisDetector = false;
    double k = 0.04;

    /// Copy the source image
    cv::Mat copy = src.clone();

    /// Apply corner detection
    goodFeaturesToTrack( src_gray,
                         corners,
                         maxCorners,
                         qualityLevel,
                         minDistance,
                         cv::Mat(),
                         blockSize,
                         gradientSize,
                         useHarrisDetector,
                         k );


    /// Draw corners detected
    std::cout << "** Number of corners detected: " << corners.size() << std::endl;
    int radius = 4;
    for( size_t i = 0; i < corners.size(); i++ )
    {
        circle( copy, corners[i], radius, cv::Scalar(rng.uniform(0,255), rng.uniform(0, 256), rng.uniform(0, 256)), cv::FILLED );
    }

    /// Show what you got
    cv::namedWindow( source_window );
    imshow( source_window, copy );
}


/**
 * @function main
 */
int main( int argc, char** argv )
{
    /// Load source image and convert it to gray
    cv::CommandLineParser parser( argc, argv, "{@input | pic3.png | input image}" );
    src = cv::imread( cv::samples::findFile( parser.get<cv::String>( "@input" ) ) );
    if( src.empty() )
    {
        std::cout << "Could not open or find the image!\n" << std::endl;
        std::cout << "Usage: " << argv[0] << " <Input image>" << std::endl;
        return -1;
    }
    cvtColor( src, src_gray, cv::COLOR_BGR2GRAY );

    /// Create Window
    cv::namedWindow( source_window );

    /// Create Trackbar to set the number of corners
    cv::createTrackbar( "Max corners:", source_window, &maxCorners, maxTrackbar, goodFeaturesToTrack_Demo );

    imshow( source_window, src );

    goodFeaturesToTrack_Demo( 0, 0 );

    cv::waitKey();
    return 0;
}

