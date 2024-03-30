cmake_minimum_required(VERSION 3.10)
project(IntersectionSimulation)

find_package(Threads REQUIRED)
add_executable(crossroads main.cpp)

target_link_libraries(IntersectionSimulation Threads::Threads)
