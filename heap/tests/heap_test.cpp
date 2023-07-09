#include "../src/include/heap.h"
#include <gtest/gtest.h>

int arr[] = {11, 5, 8, 3, 4};



TEST(Basic, get_left)
{
    EXPECT_EQ(arr[get_left(0)], 5);
}

TEST(Basic, get_right)
{
    EXPECT_EQ(arr[get_right(0)], 8);
}

TEST(Basic, get_parent)
{
    EXPECT_EQ(arr[get_parent(2)], 11);
    EXPECT_EQ(arr[get_parent(1)], 11);
}

TEST(extract, base)
{
    int arr_eq = {8, 5, 4, 3};
    EXPECT_EQ(extractMax(arr, std::size(arr)), arr_eq);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}