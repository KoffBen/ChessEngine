//
// Created by benja on 3/1/2026.
//

#include "Board.h"
#include <gtest/gtest.h>

namespace {
    // The fixture for testing SimpleArray class.
    class TestEngine : public ::testing::Test { };

    TEST_F(TestEngine, Compilation)
    {
        auto gameBoard = Board();
        EXPECT_NO_THROW({
            std::cout<<gameBoard.toString();
        });
    }
}