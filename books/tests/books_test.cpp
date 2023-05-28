#include "books.h"
#include <gtest/gtest.h>

TEST(Basic, TestingTests)
{
    EXPECT_EQ(3, 3);
}

TEST(Basic, DoesItWork)
{
    vector <vector<string>> library
    {
        {"don quixote", "1984", "freakonomics"},
        {"burnt sugar", "burnt sugar", "midnight's children"},
        {"molecular biology", "don quixote", "burnt sugar"}
    };
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}