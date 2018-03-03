#include "is_palindrome.h"
#include "gtest/gtest.h"

TEST(IsPalindromeTest, EmptyStringIsPalindrome)
{
	EXPECT_TRUE(IsPalindrome1(""));
}

TEST(IsPalindromeTest, StringIsPalindrome)
{
	EXPECT_TRUE(IsPalindrome1("asantadoglivedasadevilgodatnasa"));
}

TEST(IsPalindromeTest, StringIsNotPalindrome)
{
	EXPECT_FALSE(IsPalindrome1("helloworld"));
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
