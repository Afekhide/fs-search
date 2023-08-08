cmake_minimum_required(VERSION 3.6)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

link_directories(C:\\Users\\Dlite\\CLionProjects\\untitled1)
set(SOURCE_FILES main.c functions.h structs.h)
add_executable(app ${SOURCE_FILES})
target_link_libraries(app ws2_32.dll)