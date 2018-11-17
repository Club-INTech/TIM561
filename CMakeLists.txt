cmake_minimum_required(VERSION 3.10)
project(TIM561)

set(CMAKE_CXX_STANDARD 11)

add_executable(TIM561 main.cpp lidar/src/TIM561.cpp lidar/include/TIM561.h basic_com/include/TelegramScan.h basic_com/src/TelegramScan.cpp lidar/include/DataPoint.h)