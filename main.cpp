// Created by arslan on 3/12/19.

#include <iostream>
#include <armadillo>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


template <typename T>
arma::Mat<T> opencv_to_arma(const cv::Mat_<T> &opencv_mat)
{
    arma::Mat<T> arma_mat(opencv_mat.cols, opencv_mat.rows);
    opencv_mat.copyTo({ opencv_mat.rows, opencv_mat.cols, arma_mat.memptr() });
    return arma_mat;
}

template <typename T>
arma::Mat<T> opencv_to_arma2(const cv::Mat &opencv_mat)
{
    arma::Mat<T> arma_mat(opencv_mat.rows, opencv_mat.cols);

    for (int i = 0; i < opencv_mat.rows; ++i)
    {
        for (int j = 0; j< opencv_mat.cols; ++j)
        {
            arma_mat(i, j) = (T)opencv_mat.at<uchar>(i, j);
        }

    }

    return arma_mat;
}

int main(int argc, char** agrv)
{
    cv::Mat inputImage, inputFilter;
    cv::Mat grayScaleImage(inputImage.rows, inputImage.cols, CV_8UC1);
    cv::Mat grayScaleFilter(inputFilter.rows, inputFilter.cols, CV_8UC1);

    inputImage = cv::imread("/home/arslan/Arslan Ali/Arslan_Data/Sanja Fidler/code/lecture2/clutter.png");
    inputFilter = cv::imread("/home/arslan/Arslan Ali/Arslan_Data/Sanja Fidler/code/lecture2/filter13.png");

    cv::imshow("Input Image", inputImage);
    cv::imshow("Input Filter", inputFilter);

    if (inputImage.empty() || inputFilter.empty())
    {
        std::cout << "Can't find image" << std::endl;
        return -1;
    }

    cv::cvtColor(inputImage, grayScaleImage, cv::COLOR_BGR2GRAY);
    cv::cvtColor(inputFilter, grayScaleFilter, cv::COLOR_BGR2GRAY);

    cv::imshow("GrayScale Image", grayScaleImage);
    cv::imshow("GrayScale Filter", grayScaleFilter);

    // Convert OpenCV to Armadillo
    arma::Mat<double> armaGrayScaleImage(grayScaleImage.rows, grayScaleImage.cols);
    arma::Mat <double> armaGrayScaleFilter(grayScaleFilter.rows, grayScaleFilter.cols);

    //armaGrayScaleFilter = opencv_to_arma2<double>(grayScaleFilter);

    for (int i = 0; i < grayScaleImage.rows; i++)
    {
        for (int j = 0; j < grayScaleImage.cols; j++)
        {
            //cv::Vec3b pixelColor = testData.at<cv::Vec3b>(i);
            armaGrayScaleImage(i, j) = (double)grayScaleImage.at<uchar>(i, j);

        }
    }


    for (int i = 0; i < grayScaleFilter.rows; i++)
    {
        for (int j = 0; j < grayScaleFilter.cols; j++)
        {
            armaGrayScaleFilter(i, j) = (double)grayScaleFilter.at<uchar>(i, j);
        }

    }

    armaGrayScaleImage += 50;
    armaGrayScaleFilter += 50;



    double value = arma::sqrt(arma::sum(arma::sum(arma::pow(armaGrayScaleFilter, 2), 0), 1)).eval()(0, 0);
    //std::cout << value << std::endl;
    armaGrayScaleFilter = armaGrayScaleFilter / value;


    // convert Armadillo to Opencv
    cv::Mat image(armaGrayScaleImage.n_rows, armaGrayScaleImage.n_cols, CV_8UC1);
    cv::Mat filter(armaGrayScaleFilter.n_rows, armaGrayScaleFilter.n_cols, CV_8UC1);

    //finalImage = arma_to_opencv<uchar>(arma_mat_filter);


    for (int i = 0; i < grayScaleImage.rows; ++i)
    {
        for (int j = 0; j< grayScaleImage.cols; ++j)
        {
            image.at<uchar>(i, j) = (uchar)armaGrayScaleImage(i, j);

        }

    }


    for (int i = 0; i < grayScaleFilter.rows; ++i)
    {
        for (int j = 0; j< grayScaleFilter.cols; ++j)
        {
            filter.at<uchar>(i, j) = (uchar)armaGrayScaleFilter(i, j);

        }

    }

    imshow("Final Image ", image);
    imshow("Final Filter", filter);

    cv::waitKey();
    return 0;
}



