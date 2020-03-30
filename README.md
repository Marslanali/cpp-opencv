# open-cv-algorithms
This repository contains various algorithms including i.e. SIFT, template matching implemented in C++ using OpenCV.



## How to build OpenCV with extra modules

You can build OpenCV, so it will include the modules from this repository. Contrib modules are under constant development and it is recommended to use them alongside the master branch or latest releases of OpenCV.

Here is the CMake command for you:

`cd <opencv_build_directory>`
`cmake -DOPENCV_EXTRA_MODULES_PATH=<opencv_contrib>/modules <opencv_source_directory>`
`make -j5`

For example

`cmake -DOPENCV_EXTRA_MODULES_PATH=/home/arslanali/Downloads/opencv_contrib/modules /home/arslanali/Downloads/opencv-4.2.0`
