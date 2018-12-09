cmake_minimum_required(VERSION 3.10)
project(TIM561)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wchkp -pedantic")

file(GLOB_RECURSE SOURCES "./*/include/*.h" "./*/include/*.hpp" "./*/src/*.c" "./*/src/*.cpp")
include_directories(./*/include)
add_executable(TIM561 main.cpp lidar/src/TIM561.cpp lidar/include/TIM561.h basic_com/include/TelegramScan.h basic_com/src/TelegramScan.cpp lidar/include/DataPoint.h)