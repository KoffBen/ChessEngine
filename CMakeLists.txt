cmake_minimum_required(VERSION 3.25)
project(ChessEngine)
find_package(Threads)
find_package(Git QUIET)

# Bring in testing definitions
enable_testing()
include(FetchContent)

# Bring in GoogleTest library v1.14.0
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz)
FetchContent_MakeAvailable(googletest)

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
        include/Square.h
        include/Piece.h
        include/GridPoint.h
        include/Board.h
        include/pieces/Bishop.h
        src/GridPoint.cpp
        src/Bishop.cpp
        src/Board.cpp
        src/Square.cpp
        src/Piece.cpp
        src/King.cpp
        include/Visitor/visitor.h
        include/Visitor/PrintVisitor.h
        include/Composite/PieceSet.h
        include/Composite/Color.h
        include/newBoard.h
        include/Command/Command.h
)


#Make the project rootdirectory the working directory when we run
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(testing ${SOURCE_FILES})
add_dependencies(testing gtest)
target_link_libraries(testing gtest ${CMAKE_THREAD_LIBS_INIT})