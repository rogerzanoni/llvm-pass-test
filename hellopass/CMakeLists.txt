cmake_minimum_required(VERSION 2.8.8)

project(hellopass)

add_definitions("-std=c++11")

find_package(LLVM REQUIRED CONFIG)

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})

add_library(hellopass MODULE hellopass.cpp)