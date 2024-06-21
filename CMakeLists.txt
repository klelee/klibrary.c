cmake_minimum_required(VERSION 3.10)

# Project
project(klibrary C CXX)

add_definitions(-DVERSION="V0.0.1")

link_directories()

include_directories("${CMAKE_CURRENT_LIST_DIR}/include")

file(GLOB_RECURSE APP_SOURCES "source/*.c")

add_executable(klibrary ${APP_SOURCES})
target_link_libraries(klibrary pthread)