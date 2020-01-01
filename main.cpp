#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include "armadillo"


// convert an OpenCV matrix to Armadillo matrix. NOTE: a copy is made
template <typename T>
arma::Mat <T> cv_to_arma(const cv::Mat_<T> &src)
{
    arma::Mat<T> dst(src.cols, src.rows);
    src.copyTo({src.rows, src.cols, dst.memptr()});
    return dst;
}



int main()
{
    cv::Mat input_image, input_filter;

    input_image = cv::imread("/home/arslan/Arslan Ali/Arslan_Data/Sanja Fidler/code/lecture2/clutter.png");
    input_filter = cv::imread("/home/arslan/Arslan Ali/Arslan_Data/Sanja Fidler/code/lecture2/filter13.png");


    imshow("Input Image",input_image);
    //imshow("Filter Image",input_filter);


    cv::Mat grayScaleImage(input_image.size(),CV_8UC1);
    cvtColor(input_image,grayScaleImage,cv::COLOR_RGB2GRAY);

    cv::Mat grayScaleFilter(input_filter.size(),CV_8UC1);
    cvtColor(input_filter,grayScaleFilter,cv::COLOR_RGB2GRAY);

    imshow("GrayScale Image",grayScaleImage);
    //imshow("GrayScale Filter Image",grayScaleFilter);



    //cv::Mat* opencv_mat;    //opencv's mat, already transposed.
   // arma::mat arma_mat=reinterpret_cast<double*> (opencv_mat->data, opencv_mat->rows, opencv_mat->cols );
    //std::cout<<grayScaleFilter.rows<<"\n"<<grayScaleFilter.cols<<std::endl;

    // convert openCV matrix to Armadillo Matrix
    arma::Mat <double > filter (input_image.rows, input_image.cols);
    //filter = (grayScaleFilter.data, grayScaleFilter.rows, grayScaleFilter.cols);

    //std::cout<<input_image.at<double>(0,0)<<std::endl;
    //std::cout<<filter.n_rows<<"\n"<<filter.n_cols<<std::endl;
/*
    for (int i = 0; i < input_image.rows; ++i) {
        for (int j = 0; j < input_image.cols; ++j) {

            filter(i,j)=grayScaleFilter.at<double>(i,j);

        }

    }

    cv::Mat filter2;

    for (int i = 0; i < filter.n_rows; ++i) {
        for (int j = 0; j < filter.n_cols; ++j) {

            filter2.at<double>(i,j)  =filter(i,j);

        }

    }

*/
    //imshow("FILTER",filter2);
    //imshow("GrayScale Filter Image",grayScaleFilter);


   // std::cout<<sqrt(sum(sum(pow(filter,2),0),0))<<std::endl;

    //Armadillo to OpenCV Matrix
    //imshow("GrayScale Image2",openCVmatrix);
//




    cv::waitKey();
    return 0;
}



