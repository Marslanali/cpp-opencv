# CPP Template Matching

This repository is C++ implementation of Template Matching with OpenCV. A working demo video can be seen <a href="https://www.youtube.com/watch?v=z4NieT0z1oo&t=67s">here</a>.

## Files

```
.
├── src
├── img
├── CMakeList.txt
├── .clang-format
└── README.md
```
## Dependencies

* [CMake](https://www.mlpack.org/)   Version 3.17.5

* [OpenCV](https://www.mlpack.org/)  Version 3.17.5

* [Armadillo](http://arma.sourceforge.net/download.html)  Version 10.1.1   

## Dependencies Installation

* [CMake](https://www.mlpack.org/)   Version 3.17.5

Install [CMake](https://www.mlpack.org/) from source. 

```bash
sudo apt-get install -y -q wget
wget https://cmake.org/files/v3.17/cmake-3.17.5.tar.gz 
tar xzf cmake-3.17.5.tar.gz 
cd cmake-3.17.5 
./bootstrap -- -DCMAKE_BUILD_TYPE:STRING=Release 
make -j4 # where j is the number of core
sudo make install
```

* [OpenCV](https://www.mlpack.org/)   Version 3.17.5

Install [OpenCV](https://www.mlpack.org/) from source. 


```bash
sudo apt update && sudo apt install -y g++ unzip
wget -O opencv.zip https://github.com/opencv/opencv/archive/master.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/master.zip
unzip opencv.zip
unzip opencv_contrib.zip
```

Create build directory and switch into it, Configure, and Build.

```bash
sudo apt-get install qtbase5-dev
mkdir -p build && cd build
cmake -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib-master/modules ../opencv-master
      -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_INSTALL_PREFIX=/usr/local -DFORCE_VTK=ON 
      -DWITH_TBB=ON -DWITH_V4L=ON -DWITH_QT=ON -DWITH_OPENGL=ON -DWITH_CUBLAS=ON 
      -DCUDA_NVCC_FLAGS="-D_FORCE_INLINES" -DWITH_GDAL=ON -DWITH_XINE=ON -DBUILD_EXAMPLES=ON ..
sudo make install
```

-- Note!

To uninstall OpenCV, after install from source.

```
sudo apt-get purge libopencv*
sudo dpkg -r opencv
```

Check

```
sudo dpkg -r opencv
```

Then, go to the build directory and `sudo make uninstall`. 

* [Armadillo](http://arma.sourceforge.net/download.html)  Version 10.1.1 

```bash
sudo apt-get install liblapack-dev
wget -O opencv.zip https://github.com/opencv/opencv/archive/master.zip
cd armadillo
cmake .  # NOTE: the full stop separated from "cmake" by a space is important.
sudo make install
```

On Linux, to enable the detection of FlexiBLAS, use the additional ALLOW_FLEXIBLAS_LINUX option when running cmake:

```
cmake -DALLOW_FLEXIBLAS_LINUX=ON .
```

## Demo

To build run the following command in terminal:

```bash
mkdir build
cd build
cmake ..
make -j4 
```

```bash
$ ./template_matching
```

## References

[Template Matching1](http://www.cs.toronto.edu/~fidler/slides/2019/CSC420/lecture2.pdf)

[Template Matching2](https://docs.opencv.org/3.4/de/da9/tutorial_template_matching.html)


## To-Do List

- :ballot_box_with_check: Refactor src/include
- :negative_squared_cross_mark: Add CMake Cross Platform Support
- :negative_squared_cross_mark: Add Docker Image Support 



