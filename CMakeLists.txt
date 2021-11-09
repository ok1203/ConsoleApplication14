cmake_minimum_required(VERSION 3.20)
project(HW10Week)

set(CMAKE_CXX_STANDARD 14)

include_directories(ConsoleApplication14)

add_executable(HW10Week
        ConsoleApplication14/ConsoleApplication14.cpp
        ConsoleApplication14/Text_Preprocessor.cpp
        ConsoleApplication14/Text_Preprocessor.h
        ConsoleApplication14/Task2.cpp
        ConsoleApplication14/Task2.h)
