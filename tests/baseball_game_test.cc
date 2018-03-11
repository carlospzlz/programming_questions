#include "baseball_game.h"
#include "gtest/gtest.h"

TEST(CalPoints1Test, BasicTest1)
{
  std::vector<std::string> ops = {"5", "2", "C", "D", "+"};
  EXPECT_EQ(30, CalPoints1(ops));
}

TEST(CalPoints1Test, BasicTest2)
{
  std::vector<std::string> ops = {"5", "-2", "4", "C", "D", "9", "+", "+"};
  EXPECT_EQ(27, CalPoints1(ops));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
