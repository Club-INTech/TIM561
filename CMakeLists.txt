cmake_minimum_required(VERSION 3.12)
project(TIM561)

set(CMAKE_CXX_STANDARD 11)

add_executable(TIM561 main.cpp TIM561.cpp TIM561.h TelegramScan.h TelegramScan.cpp DataPoint.h)