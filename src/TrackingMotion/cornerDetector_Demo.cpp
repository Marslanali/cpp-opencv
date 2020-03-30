/**
 * @function cornerDetector_Demo.cpp
 * @brief Demo code for detecting corners using OpenCV built-in functions
 * @author OpenCV team
 */

#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>


/// Global variables
cv::Mat src, src_gray;
cv::Mat myHarris_dst, myHarris_copy, Mc;
cv::Mat myShiTomasi_dst, myShiTomasi_copy;

int myShiTomasi_qualityLevel = 50;
int myHarris_qualityLevel = 50;
int max_qualityLevel = 100;

double myHarris_minVal, myHarris_maxVal;
double myShiTomasi_minVal, myShiTomasi_maxVal;

cv::RNG rng(12345);

const char* myHarris_window = "My Harris corner detector";
const char* myShiTomasi_window = "My Shi Tomasi corner detector";

/**
 * @function myShiTomasi_function
 */
void myShiTomasi_function( int, void* )
{
    myShiTomasi_copy = src.clone();
    myShiTomasi_qualityLevel = MAX(myShiTomasi_qualityLevel, 1);

    for( int i = 0; i < src_gray.rows; i++ )
    {
        for( int j = 0; j < src_gray.cols; j++ )
        {
            if( myShiTomasi_dst.at<float>(i,j) > myShiTomasi_minVal + ( myShiTomasi_maxVal - myShiTomasi_minVal )*myShiTomasi_qualityLevel/max_qualityLevel )
            {
                circle( myShiTomasi_copy, cv::Point(j,i), 4, cv::Scalar( rng.uniform(0,256), rng.uniform(0,256), rng.uniform(0,256) ), cv::FILLED );
            }
        }
    }
    imshow( myShiTomasi_window, myShiTomasi_copy );
}

/**
 * @function myHarris_function
 */
void myHarris_function( int, void* )
{
    myHarris_copy = src.clone();
    myHarris_qualityLevel = MAX(myHarris_qualityLevel, 1);

    for( int i = 0; i < src_gray.rows; i++ )
    {
        for( int j = 0; j < src_gray.cols; j++ )
        {
            if( Mc.at<float>(i,j) > myHarris_minVal + ( myHarris_maxVal - myHarris_minVal )*myHarris_qualityLevel/max_qualityLevel )
            {
                circle( myHarris_copy, cv::Point(j,i), 4, cv::Scalar( rng.uniform(0,256), rng.uniform(0,256), rng.uniform(0,256) ), cv::FILLED );
            }
        }
    }
    imshow( myHarris_window, myHarris_copy );
}

/**
 * @function main
 */
int main( int argc, char** argv )
{
    /// Load source image and convert it to gray
    cv::CommandLineParser parser( argc, argv, "{@input | building.jpg | input image}" );
    src = cv::imread( cv::samples::findFile( parser.get<cv::String>( "@input" ) ) );
    if ( src.empty() )
    {
        std::cout << "Could not open or find the image!\n" << std::endl;
        std::cout << "Usage: " << argv[0] << " <Input image>" << std::endl;
        return -1;
    }
    cvtColor( src, src_gray, cv::COLOR_BGR2GRAY );

    /// Set some parameters
    int blockSize = 3, apertureSize = 3;

    /// My Harris matrix -- Using cornerEigenValsAndVecs
    cornerEigenValsAndVecs( src_gray, myHarris_dst, blockSize, apertureSize );

    /* calculate Mc */
    Mc = cv::Mat( src_gray.size(), CV_32FC1 );
    for( int i = 0; i < src_gray.rows; i++ )
    {
        for( int j = 0; j < src_gray.cols; j++ )
        {
            float lambda_1 = myHarris_dst.at<cv::Vec6f>(i, j)[0];
            float lambda_2 = myHarris_dst.at<cv::Vec6f>(i, j)[1];
            Mc.at<float>(i, j) = lambda_1*lambda_2 - 0.04f*pow( ( lambda_1 + lambda_2 ), 2 );
        }
    }

    minMaxLoc( Mc, &myHarris_minVal, &myHarris_maxVal );

    /* Create Window and Trackbar */
    cv::namedWindow( myHarris_window );
    cv::createTrackbar( "Quality Level:", myHarris_window, &myHarris_qualityLevel, max_qualityLevel, myHarris_function );
    myHarris_function( 0, 0 );

    /// My Shi-Tomasi -- Using cornerMinEigenVal
    cornerMinEigenVal( src_gray, myShiTomasi_dst, blockSize, apertureSize );

    minMaxLoc( myShiTomasi_dst, &myShiTomasi_minVal, &myShiTomasi_maxVal );

    /* Create Window and Trackbar */
    cv::namedWindow( myShiTomasi_window );
    cv::createTrackbar( "Quality Level:", myShiTomasi_window, &myShiTomasi_qualityLevel, max_qualityLevel, myShiTomasi_function );
    myShiTomasi_function( 0, 0 );

    cv::waitKey();
    return 0;
}

