#include "../src/include/levelsum.h"
#include <gtest/gtest.h>

TEST(Basic, Run)
{
    int x =3;
    EXPECT_EQ(3,x);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}