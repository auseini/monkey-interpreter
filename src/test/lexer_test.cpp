#include <gtest/gtest.h>
#include <string>
TEST(LexerTest, TestNextToken) {
    std::string input = "=+(){},;";
    

    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7*6, 42);
}
