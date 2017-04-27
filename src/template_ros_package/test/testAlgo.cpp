/**
 * File description
 */

// Bring in my package's API, which is what I'm testing
#include "algo.hpp"
// Bring in gtest
#include <gtest/gtest.h>

// Declare a test
TEST(TestAlgo, testEq)
{
        EXPECT_EQ("hello world 45", text_count(45));
}

// Declare another test
TEST(TestAlgo, testTrue)
{
        EXPECT_TRUE(strcmp("hello world 45", text_count(45).c_str())==0);
}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv){
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
