cmake_minimum_required(VERSION 3.6)
project(MyStack)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")

set(SOURCE_FILES
        main.cpp
        MyStack.cpp
        MyStack.h
    )

add_executable(
        MyStack
        ${SOURCE_FILES})
