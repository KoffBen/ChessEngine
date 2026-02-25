cmake_minimum_required(VERSION 3.25)
project(ChessEngine)
find_package(Threads)
find_package(Git QUIET)

#Set compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -pedantic-errors -g")

#Include project headers
include_directories(./include)

#Define the source files and dependencies
set(SOURCE_FILES
    tests/main.cpp
)


#Make the project rootdirectory the working directory when we run
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(testing ${SOURCE_FILES})