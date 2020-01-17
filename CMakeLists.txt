cmake_minimum_required(VERSION 3.15)
project(template_matching_opencv)

set(CMAKE_CXX_STANDARD 11)

add_executable(template_matching_opencv main.cpp src/video_capture_live_camera.cpp)

## Armadillo & OpenCV packages
find_package(OpenCV 4.2 REQUIRED)
find_package(Armadillo 5.2.0 REQUIRED)

#find opencv & armadillo libraries
find_library(ARMADILLO_LIBRARIES armadillo)
find_library(OPENCV_LIBRARIES opencv)

#target includes
include_directories(include ${PYTHON_INCLUDE_DIRS} ${ARMADILLO_INCLUDE_DIRS} ${MLPACK_INCLUDE_DIRS} ${OPENCV_INCLUDE_DIRS})

#target link libraries
target_link_libraries(template_matching_opencv ${PYTHON_LIBRARIES}  ${ARMADILLO_LIBRARIES} ${OpenCV_LIBRARIES} libmlpack.so )