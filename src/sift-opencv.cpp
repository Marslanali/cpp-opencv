//
// Created by arslanali on 29/3/20.
//

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/xfeatures2d.hpp> //Thanks to Alessandro


int main(int argc, const char* argv[])
{
    cv::Mat input = cv::imread("/home/arslanali/Downloads/opencv-4.2.0/doc/py_tutorials/py_feature2d/py_sift_intro/images/sift_keypoints.jpg", 0); //Load as grayscale
    cv::Ptr<cv::xfeatures2d::SIFT> detector = cv::xfeatures2d::SIFT::create(0.3); // have to use Ptr and create()
    std::vector<cv::KeyPoint> keypoints;
    detector->detect(input, keypoints);

    // Add results to image and save.
    cv::Mat output;
    cv::drawKeypoints(input, keypoints, output);
    cv::imshow("Result", output);
    cv::imwrite("../results/sift/sift_result.jpg", output);
    return 0;
}


/*
#include "opencv2/xfeatures2d.hpp" // new module in opencv_contrib

cv::Ptr<cv::xfeatures2d::SIFT> sift = cv::xfeatures2d::SIFT::create(0.3); // have to use Ptr and create()

std::vector<cv::KeyPoint> keypoints;
cv::Mat descriptors;

sift->detectAndCompute(keypoints, Mat(), descriptors);*/
