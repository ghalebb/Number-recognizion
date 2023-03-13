cmake_minimum_required(VERSION 3.16)
project(ex4)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex4 main.cpp Activation.h Matrix.h Dense.h MlpNetwork.h Matrix.cpp Activation.cpp Digit.h Dense.cpp MlpNetwork.cpp)