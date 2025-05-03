cmake_minimum_required(VERSION 3.31)
project(FireStack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
# NB for later - indiv apps will include their own cmakelists
add_subdirectory(apps)