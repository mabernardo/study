cmake_minimum_required(VERSION 3.10)
project(sfml)

set(CMAKE_CXX_STANDARD 17)

find_library(SFML_GRAPHICS sfml-graphics)
find_library(SFML_WINDOW sfml-window)
find_library(SFML_SYSTEM sfml-system)

add_executable(sfml main.cpp)

target_link_libraries(sfml "${SFML_GRAPHICS}")
target_link_libraries(sfml "${SFML_WINDOW}")
target_link_libraries(sfml "${SFML_SYSTEM}")
