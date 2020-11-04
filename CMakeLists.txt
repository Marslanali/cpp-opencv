############################################################
# Find CMake, Compiler Version, and OS
############################################################
cmake_minimum_required(VERSION 3.5.1)
project(template_matching_opencv)
set(CMAKE_CXX_STANDARD 11)

message(STATUS "CMake version   : " ${CMAKE_SYSTEM_VERSION})
message(STATUS "Compiler        : " ${CMAKE_CXX_COMPILER})
message(STATUS "Operating System: " ${CMAKE_SYSTEM})
message(STATUS "SYSTEM PROCESSOR: " ${CMAKE_SYSTEM_PROCESSOR})

############################################################
# Find Armadillo and OpenCV packages
############################################################
 
find_package(OpenCV  REQUIRED)
find_package(Armadillo 5.2.0 REQUIRED)

############################################################
# Find Armadillo and OpenCV libraries
############################################################

find_library(ARMADILLO_LIBRARIES armadillo)
find_library(OPENCV_LIBRARIES opencv)

############################################################
# Target Include directories
############################################################

include_directories(include ${PYTHON_INCLUDE_DIRS} ${ARMADILLO_INCLUDE_DIRS} ${MLPACK_INCLUDE_DIRS} ${OPENCV_INCLUDE_DIRS})

############################################################
# Create a executable for template-matching
############################################################

add_executable(template-matching ${PROJECT_SOURCE_DIR}/src/template_matching.cpp )

############################################################
# Target Link Libaries
############################################################

target_link_libraries(template-matching ${PYTHON_LIBRARIES} ${ARMADILLO_LIBRARIES} ${OpenCV_LIBRARIES} )


