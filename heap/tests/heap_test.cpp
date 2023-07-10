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
    int arr_eq[] = {8, 5, 4, 3};

    std::string arr_s = arrstr(extractMax(arr, std::size(arr)), std::size(arr));
    std::string eq_s = arrstr(arr_eq, std::size(arr_eq));
    EXPECT_EQ(arr_s, eq_s);
}

TEST(extract, 2elem)
{
    int arr[] = {3, 1};
    int arr_eq[] = {1};

    std::string arr_s = arrstr(extractMax(arr, std::size(arr)), std::size(arr));
    std::string eq_s = arrstr(arr_eq, std::size(arr_eq));
    EXPECT_EQ(arr_s, eq_s);
}

TEST(extract, multipleSwaps)
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr_eq[] = {9, 7, 8, 3, 6, 5, 4, 1, 2};

    std::string arr_s = arrstr(extractMax(arr, std::size(arr)), std::size(arr));
    std::string eq_s = arrstr(arr_eq, std::size(arr_eq));
    EXPECT_EQ(arr_s, eq_s);
}

TEST(extract, repeatDeleteHell)
{
    int arr[] = {323, 252, 282, 121, 131, 222, 141, 66, 111, 85, 50, 182, 107, 64, 91, 15, 20};
    int arr_eq[] = {182, 131, 141, 121, 85, 107, 64, 66, 111, 15, 50, 70, 91};
    for (int i = 0; i < 4; i++)
        extractMax(arr, std::size(arr));

    std::string arr_s = arrstr(arr, std::size(arr));
    std::string eq_s = arrstr(arr_eq, std::size(arr_eq));
    EXPECT_EQ(arr_s, eq_s);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}