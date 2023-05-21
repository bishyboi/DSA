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

TEST(BasicExamples, et_tu)
{
    std::string S = "et tu, brute";
    int L = 1;
    EXPECT_EQ(2, suffixCount(S, L) );
}

TEST(BasicExamples, ANPANMAN)
{
  std::string S = "ANPANMAN";
  int L = 2;
  EXPECT_EQ(3, suffixCount(S,L));
}

TEST(BasicExamples, NAMPNAM)
{
  std::string S = "ANAMPNAM";
  int L = 2;
  EXPECT_EQ(2, suffixCount(S,L));
}

TEST(BasicExamples, DoubleCount)
{
  std::string S = "ABBABABA";
  int L=3;
  EXPECT_EQ(1, suffixCount(S,L));
}

TEST(BasicExamples, SkippingTooFar)
{
  std::string S = "AAAAAAAAAAAAAAAA";
  int L=3;
  EXPECT_EQ(5, suffixCount(S,L));
}

TEST(BasicExamples, SkippingOnEvens)
{
  std::string S = "aaaaaa";
  int L=3;
  EXPECT_EQ(2, suffixCount(S,L));
}

TEST(BasicExamples, DoubleCount2)
{
  std::string S = "AABAACAADAABAABA";
  int L = 4;
  EXPECT_EQ(2, suffixCount(S,L));
}

TEST(BasicExamples, CheckingEnds)
{
  std::string S = "ABAAABAAAAA";
  int L = 4;
  EXPECT_EQ(1, suffixCount(S,L));
}

TEST(BreakYoCode, L0)
{
  std::string S = "";
  int L=0;
  EXPECT_EQ(0, suffixCount(S,L));
}

TEST(BreakYoCode, LGTS)
{
  std::string S = "aa";
  int L=6;
  EXPECT_EQ(0, suffixCount(S,L));
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}