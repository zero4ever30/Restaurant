cmake_minimum_required(VERSION 3.19)
project(Final_Project)

set(CMAKE_CXX_STANDARD 20)


add_subdirectory(RestLib)

include_directories(RestLib)
link_libraries(RestLib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.1.0\\mingw81_64")
find_package(Qt6Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/IngredientList.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Database.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/FinanceStatistics.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(Final_Project main.cpp RestLib/Restaurant.cpp RestLib/Restaurant.hpp qtwin.cpp qtwin.h qtwin.ui)
target_link_libraries(Final_Project Qt6::Widgets Qt6::Core Qt6::Gui)
