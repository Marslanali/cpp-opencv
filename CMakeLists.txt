cmake_minimum_required(VERSION 3.5.1)
project(template_matching_opencv)

set(CMAKE_CXX_STANDARD 11)

add_executable(template-matching
        ${PROJECT_SOURCE_DIR}/src/template_matching.cpp )

add_executable(video-capture-live-camera
        ${PROJECT_SOURCE_DIR}/src/video_capture_live_camera.cpp )

add_executable(sift-opencv 
	${PROJECT_SOURCE_DIR}/src/sift-opencv.cpp  )

add_executable(cornerDetector_Demo
	${PROJECT_SOURCE_DIR}/src/TrackingMotion/cornerDetector_Demo.cpp )

add_executable(cornerHarris_Demo
	${PROJECT_SOURCE_DIR}/src/TrackingMotion/cornerHarris_Demo.cpp)

add_executable(cornerSubPix_Demo
	${PROJECT_SOURCE_DIR}/src/TrackingMotion/cornerSubPix_Demo.cpp)

add_executable(goodFeaturesToTrack_Demo
	${PROJECT_SOURCE_DIR}/src/TrackingMotion/goodFeaturesToTrack_Demo.cpp)

add_executable(birdeyeview_Demo
		${PROJECT_SOURCE_DIR}/src/example_19-01.cpp)


## Armadillo & OpenCV packages
find_package(OpenCV 4.2.0 REQUIRED)
find_package(Armadillo 5.2.0 REQUIRED)

#find opencv & armadillo libraries
find_library(ARMADILLO_LIBRARIES armadillo)
find_library(OPENCV_LIBRARIES opencv)

#target includes
include_directories(include ${PYTHON_INCLUDE_DIRS} ${ARMADILLO_INCLUDE_DIRS} ${MLPACK_INCLUDE_DIRS} ${OPENCV_INCLUDE_DIRS})

#target link libraries
target_link_libraries(template-matching ${PYTHON_LIBRARIES}  ${ARMADILLO_LIBRARIES} ${OpenCV_LIBRARIES} libmlpack.so )

#target link libraries
target_link_libraries(sift-opencv ${OpenCV_LIBRARIES} )

#target link libraries
target_link_libraries(video-capture-live-camera ${OpenCV_LIBRARIES} )

#target link libraries
target_link_libraries(cornerHarris_Demo ${OpenCV_LIBRARIES} )

#target link libraries
target_link_libraries(cornerDetector_Demo ${OpenCV_LIBRARIES} )

#target link libraries
target_link_libraries(cornerSubPix_Demo ${OpenCV_LIBRARIES} )

#target link libraries
target_link_libraries(goodFeaturesToTrack_Demo ${OpenCV_LIBRARIES} )


#target link libraries
target_link_libraries(birdeyeview_Demo ${OpenCV_LIBRARIES} )

