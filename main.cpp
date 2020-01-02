// Created by arslan on 3/12/19.

#include <iostream>
#include <armadillo>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

template <typename T>
arma::Mat <T> arma_computations (arma::Mat<T> &arma_input1, arma::Mat<T> &arma_input2)
{
    arma::Mat <T> arma_output(arma_input1.n_rows, arma_input2.n_cols);
    arma_output = arma_input1 + arma_input2;
    return arma_output;
}


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
    cv::Mat inputImage, inputFilter, inputImage2;
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

    arma::Mat<double> data1 = arma::randu<arma::Mat<double>>(2, 2);
    arma::Mat<double> data2 = arma::randu<arma::Mat<double>>(2, 2);

    arma::Mat<double> outputData(data1.n_rows, data1.n_cols);
    outputData = arma_computations<double>(data1, data2);

    //cv::Mat testData(3, 3, CV_8UC1);
    //cv::Vec3b pixelColor = grayScaleFilter.at<cv::Vec3b>();

    //std::cout << grayScaleFilter << std::endl;
    //std::cout << " TestData:\n" << pixelColor << std::endl;
    //std::cout << data1 << std::endl;
    //td::cout << " Data1 " << data1(0, 1) << std::endl;


    arma::Mat <int> arma_mat(grayScaleFilter.rows, grayScaleFilter.cols);
    for (int i = 0; i < arma_mat.n_rows; i++)
    {
        for (int j = 0; j < arma_mat.n_cols; j++)
        {

            //cv::Vec3b pixelColor = testData.at<cv::Vec3b>(i);
            arma_mat(i, j) = (int)grayScaleFilter.at<uchar>(i,j);

        }
    }

    //std::cout <<arma_mat << std::endl;

/*
    arma::Mat <int> arma_mat1(inputImage.rows, inputImage.cols);
    arma::Mat <int> arma_mat2(inputImage.rows, inputImage.cols);

    //outputImage = opencv_to_arma<double>(inputImage);
    //std::cout << outputImage << std::endl;

    for (int i = 0; i < inputImage.rows; i++)
    {
        for (int j = 0; j < inputImage.cols; j++)
        {

            arma_mat1(i, j) = (int)inputImage.at<uchar>(i,j);
            arma_mat2(i, j) = (int)inputImage2.at<uchar>(i,j);

        }

    }


    arma::Mat <int> arma_output(inputImage.rows, inputImage.cols);
    arma_output = arma_mat1 + 2;
    //std::cout << arma_output << std::endl;
    */


    // Convert OpenCV to Armadillo
    arma::Mat<uchar> armaGrayScaleImage(grayScaleImage.rows, grayScaleImage.cols);
    for (int i = 0; i < armaGrayScaleImage.n_rows; i++)
    {
        for (int j = 0; j < armaGrayScaleImage.n_cols; j++)
        {

            //cv::Vec3b pixelColor = testData.at<cv::Vec3b>(i);
            armaGrayScaleImage(i, j) = grayScaleImage.at<uchar>(i,j);

        }
    }

    armaGrayScaleImage += 100;

    std::cout<<armaGrayScaleImage<<std::endl;

    // convert Armadillo to Opencv
    cv::Mat finalImage(armaGrayScaleImage.n_rows, armaGrayScaleImage.n_cols, CV_8UC1);
    //finalImage = arma_to_opencv<uchar>(arma_mat_filter);


    for (int i = 0; i < armaGrayScaleImage.n_rows; ++i)
    {
        for (int j = 0; j< armaGrayScaleImage.n_cols; ++j)
        {
            finalImage.at<uchar>(i, j) = armaGrayScaleImage(i, j);
        }

    }

    imshow("Final Output ", finalImage);


    std::cout<<sqrt(sum(sum(pow(armaGrayScaleImage,2),0),0))<<std::endl;

    cv::waitKey();
    return 0;
}



