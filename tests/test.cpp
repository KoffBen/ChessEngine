//
// Created by benja on 3/1/2026.
//

#include <iostream>

#include "../include/NewBoard.h"
#include <gtest/gtest.h>

namespace {
    // The fixture for testing SimpleArray class.
    class TestEngine : public ::testing::Test { };

    TEST_F(TestEngine, Compilation)
    {
        auto gameBoard = NewBoard();
        EXPECT_NO_THROW(
            std::cout<<"Hello";
        );
    }
}