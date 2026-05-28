//
// Created by benja on 3/1/2026.
//

#include <iostream>

#include "../include/NewBoard.h"
#include <gtest/gtest.h>

#include "Visitor/PrintVisitor.h"

namespace {
    // The fixture for testing SimpleArray class.
    class TestEngine : public ::testing::Test { };

    TEST_F(TestEngine, Compilation)
    {
        std::stringstream testString;
        auto gameBoard = NewBoard();
        auto printVisitor = PrintVisitor(std::cout);
        EXPECT_NO_THROW(
            gameBoard.defaultSetup();
            gameBoard.accept(printVisitor);
        );
    }
}
