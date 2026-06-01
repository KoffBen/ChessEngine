//
// Created by benja on 3/1/2026.
//

#include <iostream>

#include "../include/Core/Board.h"
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
        for (auto tmp = GridPoint(0, 0); tmp.x < 8; ++tmp.x)
        {
            for (tmp.y = 0; tmp.y < 8; ++tmp.y)
            {
                const Piece* tmpPiece = gameBoard.getPiece(tmp);
                if (tmpPiece != nullptr)
                {
                    EXPECT_EQ(tmpPiece->getPos(), tmp);
                }
            }
        }
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
        EXPECT_TRUE(movePawn.execute());
        gameBoard.accept(printVisitor);
        EXPECT_TRUE(movePawn.undo());
        gameBoard.accept(printVisitor);

        auto moveQueen = MovePiece(context, gameBoard.getPiece(GridPoint(3, 0)), GridPoint(3, 7));

        for (int i = 0; i < 10; ++i)
        {
            EXPECT_FALSE(moveQueen.execute());

            //gameBoard.accept(printVisitor);

            EXPECT_FALSE(moveQueen.undo());

            //gameBoard.accept(printVisitor);
        }

        for (auto tmpGP = GridPoint(0, 0); tmpGP.x < 8; ++tmpGP.x)
        {
            for (tmpGP.y = 0; tmpGP.y < 8; ++tmpGP.y)
            {
                const Piece* tmpPiece = gameBoard.getPiece(tmpGP);
                if (tmpPiece != nullptr)
                {
                    EXPECT_EQ(tmpPiece->getPos(), tmpGP);
                }
            }
        }


        int j = 0;
        GridPoint tmp;
        while (j < 8)
        {
            for (int i = 0; i < 8; ++i)
            {
                if (i % 5 != 1)
                {
                    for (tmp = GridPoint(0, 0); tmp.x < 8; ++tmp.x)
                    {
                        for (tmp.y = 0; tmp.y < 8; ++tmp.y)
                        {
                            auto movePiece = MovePiece(context, gameBoard.getPiece(GridPoint(i, j)), tmp);
                            EXPECT_FALSE(movePiece.execute());
                            EXPECT_FALSE(movePiece.undo());
                        }
                    }
                } else
                {
                    for (tmp = GridPoint(0, 0); tmp.x < 8; ++tmp.x)
                    {
                        for (tmp.y = 0; tmp.y < 8; ++tmp.y)
                        {
                            auto movePiece = MovePiece(context, gameBoard.getPiece(GridPoint(i, j)), tmp);
                            if (((j == 0 && tmp.y == 2) || (j == 7 && tmp.y == 5)) && (tmp.x == i - 1 || tmp.x == i + 1))
                            {
                                EXPECT_TRUE(movePiece.execute());
                                EXPECT_TRUE(movePiece.undo());
                            } else
                            {
                                EXPECT_FALSE(movePiece.execute());
                                EXPECT_FALSE(movePiece.undo());
                            }
                        }
                    }
                }
            }
            j += 7;
        }
        gameBoard.accept(printVisitor);

    }
}
