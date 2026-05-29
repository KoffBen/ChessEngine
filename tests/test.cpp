//
// Created by benja on 3/1/2026.
//

#include <iostream>

#include "../include/Board.h"
#include <gtest/gtest.h>

#include "Command/MovePiece.h"
#include "Visitor/PrintVisitor.h"

namespace {
    // The fixture for testing SimpleArray class.
    class TestEngine : public ::testing::Test { };

    TEST_F(TestEngine, Compilation)
    {
        std::stringstream testString;
        auto gameBoard = Board();
        auto printVisitor = PrintVisitor(std::cout);
        EXPECT_NO_THROW(
            gameBoard.defaultSetup();
            gameBoard.accept(printVisitor);
        );
    }

    TEST_F(TestEngine, Movement)
    {
        std::stringstream testString;
        auto gameBoard = Board();
        auto printVisitor = PrintVisitor(std::cout);

        gameBoard.defaultSetup();
        gameBoard.accept(printVisitor);
        Context* context = gameBoard.getContext();

        auto movePawn = MovePiece(context, gameBoard.getPiece(GridPoint(3, 1)), GridPoint(3, 3));
        movePawn.execute();
        gameBoard.accept(printVisitor);
        movePawn.undo();
        gameBoard.accept(printVisitor);

        auto moveQueen = MovePiece(context, gameBoard.getPiece(GridPoint(3, 0)), GridPoint(3, 7));

        ASSERT_TRUE(
            moveQueen.execute();
        );
        gameBoard.accept(printVisitor);
        moveQueen.undo();
        gameBoard.accept(printVisitor);
    }
}
