cmake_minimum_required(VERSION 3.8)

project(app CXX)

set(CMAKE_CXX_STANDARD 17)

set(APP_DIR "${CMAKE_CURRENT_LIST_DIR}")

add_executable(app main.cpp)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(app sfml-graphics sfml-audio)

