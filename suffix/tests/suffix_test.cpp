// et tu, brute ; 1
// expected: 2

// ANPANMAN ; 2
// expected: 3

// ANAMPNAM ; 2
// expected: 2
#include <gtest/gtest.h>
#include <suffix.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);

  EXPECT_EQ(6,6);


}

TEST(Class2, MessingAround)
{
    std::string S = "et tu, brute";
    int L = 1;
    EXPECT_EQ(2, suffixCount(S, L) );
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}