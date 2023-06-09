#include "../src/include/iqr.h"
#include <gtest/gtest.h>

TEST(Basic, s5)
{
    int set[5] = {1,2,3,4,5};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    EXPECT_EQ(3.0, interQuartile(head));
}

TEST(Basic, s7)
{
    int set[7] = {1,2,3,4,5,6,7};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    EXPECT_EQ(4.0, interQuartile(head));
}

TEST(Basic, s8)
{
    int set[8] = {1,2,3,4,5,6,7,8};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    EXPECT_EQ(4.0, interQuartile(head));
}

TEST(Basic, s9)
{
    int set[9] = {1,2,3,4,5,6,7,8,9};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    EXPECT_EQ(5.0, interQuartile(head));
}

TEST(Basic, s10)
{
    int set[10] = {1,2,3,4,5,6,7,8,9,10};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    EXPECT_EQ(5.0, interQuartile(head));    
}

TEST(Basic, s11)
{
    int set[11] = {1,2,3,4,5,6,7,8,9,10,11};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    EXPECT_EQ(6.0, interQuartile(head));     
}

TEST(Basic, s20)
{
    int set[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    EXPECT_EQ(10.0, interQuartile(head));
}

TEST(Randomized, s5)
{
    int set[5] = {0, 15, 27, 1034, 2048};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    EXPECT_EQ(1533.5, interQuartile(head));
}

TEST(Randomized, s6)
{
    int set[6] = {0, 5, 9, 15, 45, 46};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    EXPECT_EQ(40, interQuartile(head));
}

TEST(Randomized, s7)
{
    int set[7] = {1, 18, 80, 91, 95, 103, 107};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    EXPECT_EQ(85, interQuartile(head));
}

TEST(Randomized, s8)
{
    int set[8] = {8, 12, 13, 17, 22, 29, 31, 40};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    EXPECT_EQ(17.5, interQuartile(head));
}

TEST(Randomized, s9)
{
    int set[9] = {2, 6, 6, 8, 9, 10, 15, 16, 33};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    EXPECT_EQ(9.5, interQuartile(head));
}

TEST(EdgeCase, s0)
{
    Node* head = nullptr;
    EXPECT_EQ(0.0, interQuartile(head));
}

// https://www.statisticshowto.com/calculators/interquartile-range-calculator/ says that this doesn't exist... so return nullptr or 0?
TEST(EdgeCase, s1)
{
    Node* head= new Node();
    head->value = 1;
    EXPECT_EQ(0.0, interQuartile(head));
}

TEST(EdgeCase, s2)
{
    int set[2] = {1,2};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    EXPECT_EQ(1.0, interQuartile(head));
}

TEST(EdgeCase, s3)
{
    int set[3] = {1,2,3};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    EXPECT_EQ(2.0, interQuartile(head));
}

TEST(EdgeCase, s4)
{
    int set[4] = {1,2,3,4};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    EXPECT_EQ(2.0, interQuartile(head));
}

TEST(UnitTestingFunctionality, Printing)
{
    int set[5] = {1,2,3,4,5};

    printLinkedList(setToList(set, sizeof(set)/sizeof(int)));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}