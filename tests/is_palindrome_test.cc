#include "is_palindrome.h"
#include "gtest/gtest.h"

TEST(IsPalindrome1Test, EmptyStringIsPalindrome) {
  EXPECT_TRUE(IsPalindrome1(""));
}

TEST(IsPalindrome1Test, StringIsPalindrome) {
  EXPECT_TRUE(IsPalindrome1("asantadoglivedasadevilgodatnasa"));
}

TEST(IsPalindrome1Test, StringIsNotPalindrome) {
  EXPECT_FALSE(IsPalindrome1("helloworld"));
}

TEST(IsPalindrome2Test, EmptyStringIsPalindrome) {
  EXPECT_TRUE(IsPalindrome2(""));
}

TEST(IsPalindrome2Test, StringIsPalindrome) {
  EXPECT_TRUE(IsPalindrome2("asantadoglivedasadevilgodatnasa"));
}

TEST(IsPalindrome2Test, StringIsNotPalindrome) {
  EXPECT_FALSE(IsPalindrome2("helloworld"));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
