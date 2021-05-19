cmake_minimum_required(VERSION 3.19)
project(Final_Project)

set(CMAKE_CXX_STANDARD 20)


add_subdirectory(RestLib)

include_directories(RestLib)
link_libraries(RestLib)

add_executable(Final_Project main.cpp RestLib/test.cpp RestLib/test.hpp)