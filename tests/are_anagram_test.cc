#include "are_anagram.h"
#include "gtest/gtest.h"

TEST(AreAnagram1Test, EmptyStrings)
{
  EXPECT_TRUE(AreAnagram1(std::string(), std::string()));
}

TEST(AreAnagram1Test, AnagramStrings)
{
  std::string str1("dormitory");
  std::string str2("dirtyroom");
  EXPECT_TRUE(AreAnagram1(str1, str2));
}

TEST(AreAnagram1Test, NonAnagramStrings)
{
  std::string str1("dormitory");
  std::string str2("dirtyrhum");
  EXPECT_FALSE(AreAnagram1(str1, str2));
}

TEST(AreAnagram2Test, EmptyStrings)
{
  EXPECT_TRUE(AreAnagram2(std::string(), std::string()));
}

TEST(AreAnagram2Test, AnagramStrings)
{
  std::string str1("dormitory");
  std::string str2("dirtyroom");
  EXPECT_TRUE(AreAnagram2(str1, str2));
}

TEST(AreAnagram2Test, NonAnagramStrings)
{
  std::string str1("dormitory");
  std::string str2("dirtyrhum");
  EXPECT_FALSE(AreAnagram2(str1, str2));
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
