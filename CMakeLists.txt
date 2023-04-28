cmake_minimum_required(VERSION 3.26)
project(FastMediaShare)

set(CMAKE_CXX_STANDARD 17)

add_executable(FastMediaShare src/main.cpp src/server/server.cpp src/server/server.h)

find_package(cxxopts CONFIG REQUIRED)
target_link_libraries(FastMediaShare PRIVATE cxxopts::cxxopts)
