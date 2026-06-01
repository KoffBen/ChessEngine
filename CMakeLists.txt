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
        include/pieces/Piece.h
        include/pieces/Bishop.h
        src/Pieces/Bishop.cpp
        src/Pieces/King.cpp
        include/Visitor/visitor.h
        include/Visitor/PrintVisitor.h
        include/Composite/PieceSet.h
        include/Composite/Color.h
        include/Core/Board.h
        include/Command/Command.h
        include/Core/Context.h
        include/Core/GridPoint.h
        src/Pieces/Queen.cpp
        src/Pieces/Pawn.cpp
        src/Pieces/Knight.cpp
        include/Command/DefaultBoard.h
        src/Command/DefaultBoard.cpp
        include/Command/MakePiece.h
        src/Composite/PieceSet.cpp
        src/Composite/Color.cpp
        src/Core/Board.cpp
        include/FactoryInterpreter/CommandFactory.h
        src/FactoryInterpreter/CommandFactory.cpp
        src/Pieces/Rook.cpp
        tests/test.cpp
        src/Command/Command.cpp
        src/Visitor/PrintVisitor.cpp
        include/Command/MovePiece.h
        src/Command/MovePiece.cpp
        include/PassKey/PassKey.h
        include/Facade/Game.h
        src/Facade/Game.cpp
)


#Make the project rootdirectory the working directory when we run
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(testing ${SOURCE_FILES})
add_dependencies(testing gtest)
target_link_libraries(testing gtest ${CMAKE_THREAD_LIBS_INIT})