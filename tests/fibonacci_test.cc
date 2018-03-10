#include "fibonacci.h"
#include "gtest/gtest.h"

TEST(Fibonacci1Test, NegativeN) {
  EXPECT_DEATH(Fibonacci1(-1), ".*");
}

TEST(Fibonacci1Test, Zero) {
  EXPECT_EQ(0, Fibonacci1(0));
}

TEST(Fibonacci1Test, BasicTest1) {
  EXPECT_EQ(2, Fibonacci1(3));
}

TEST(Fibonacci1Test, BasicTest2) {
  EXPECT_EQ(8, Fibonacci1(6));
}

TEST(Fibonacci1Test, BasicTest3) {
  EXPECT_EQ(55, Fibonacci1(10));
}

TEST(Fibonacci2Test, NegativeN) {
  EXPECT_DEATH(Fibonacci2(-1), ".*");
}

TEST(Fibonacci2Test, Zero) {
  EXPECT_EQ(0, Fibonacci2(0));
}

TEST(Fibonacci2Test, BasicTest1) {
  EXPECT_EQ(2, Fibonacci2(3));
}

TEST(Fibonacci2Test, BasicTest2) {
  EXPECT_EQ(8, Fibonacci2(6));
}

TEST(Fibonacci2Test, BasicTest3) {
  EXPECT_EQ(55, Fibonacci2(10));
}

TEST(Fibonacci3Test, Zero) {
  EXPECT_EQ(0, Fibonacci3(0));
}

TEST(Fibonacci3Test, BasicTest1) {
  EXPECT_EQ(2, Fibonacci3(3));
}

TEST(Fibonacci3Test, BasicTest2) {
  EXPECT_EQ(8, Fibonacci3(6));
}

TEST(Fibonacci3Test, BasicTest3) {
  EXPECT_EQ(55, Fibonacci3(10));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
