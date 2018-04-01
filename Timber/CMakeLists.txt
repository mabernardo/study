cmake_minimum_required(VERSION 3.10)
project(Timber)

set(CMAKE_CXX_STANDARD 17)

find_library(SFML_GRAPHICS sfml-graphics)
find_library(SFML_WINDOW sfml-window)
find_library(SFML_SYSTEM sfml-system)

add_executable(Timber Timber.cpp)

target_link_libraries(Timber "${SFML_GRAPHICS}")
target_link_libraries(Timber "${SFML_WINDOW}")
target_link_libraries(Timber "${SFML_SYSTEM}")

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})