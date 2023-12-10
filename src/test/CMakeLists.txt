cmake_minimum_required(VERSION 3.14)

enable_testing()

add_executable(
    lexer_test
    lexer_test.cpp
)
target_link_libraries(
    lexer_test
    GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(lexer_test)
