#include "first_non_repeated.h"
#include "gtest/gtest.h"

TEST(FirstNonRepeated1Test, EmptyVector)
{
  EXPECT_DEATH(FirstNonRepeated1<int>({}), ".*");
}

TEST(FirstNonRepeated1Test, ThereAreNotNonRepeated)
{
  EXPECT_DEATH(FirstNonRepeated1<int>({1, 2, 3, 1, 2, 3}), ".*");
}

TEST(FirstNonRepeated1Test, GeneralCaseWithInt)
{
  EXPECT_EQ(7, FirstNonRepeated1<int>({1, 2, 3, 7, 11, 3, 2, 1}));
}

TEST(FirstNonRepeated1Test, GeneralCaseWithChar)
{
  EXPECT_EQ('b', FirstNonRepeated1<char>({'a', 'b', 'c', 'a'}));
}

TEST(FirstNonRepeated2Test, EmptyVector)
{
  EXPECT_DEATH(FirstNonRepeated2<int>({}), ".*");
}

TEST(FirstNonRepeated2Test, ThereAreNotNonRepeated)
{
  EXPECT_DEATH(FirstNonRepeated2<int>({1, 2, 3, 1, 2, 3}), ".*");
}

TEST(FirstNonRepeated2Test, GeneralCaseWithInt)
{
  EXPECT_EQ(7, FirstNonRepeated2<int>({1, 2, 3, 7, 11, 3, 2, 1}));
}

TEST(FirstNonRepeated2Test, GeneralCaseWithChar)
{
  EXPECT_EQ('b', FirstNonRepeated2<char>({'a', 'b', 'c', 'a'}));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
