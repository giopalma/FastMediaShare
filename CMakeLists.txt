cmake_minimum_required(VERSION 3.26)
project(FastMediaShare)

set(CMAKE_CXX_STANDARD 17)

add_executable(FastMediaShare src/main.cpp src/server/server.cpp src/server/server.h src/server/server.cpp src/server/server.h src/tools.cpp src/tools.h)

find_package(cxxopts CONFIG REQUIRED)
find_package(CURL REQUIRED)
find_package(oatpp CONFIG REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(FastMediaShare PRIVATE cxxopts::cxxopts ${CURL_LIBRARIES} oatpp::oatpp)

