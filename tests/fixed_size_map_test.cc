#include "fixed_size_map.h"
#include "gtest/gtest.h"

TEST(FixedSizeMap1, InsertAndFind)
{
    FixedSizeMap1 map(1);
    map.insert("one", "foo");
    EXPECT_EQ(map.find("one"), "foo");
}

TEST(FixedSizeMap1, EraseAndFind)
{
    FixedSizeMap1 map(1);
    map.insert("one", "foo");
    map.erase("one");
    EXPECT_EQ(map.find("one"), "");
}

TEST(FixedSizeMap1, CapacityReached)
{
    FixedSizeMap1 map(1);
    map.insert("one", "foo");
    map.insert("two", "spam");
    EXPECT_EQ(map.find("one"), "");
    EXPECT_EQ(map.find("two"), "spam");
}

TEST(FixedSizeMap1, CapacityReachedLRURemoved)
{
    FixedSizeMap1 map(2);
    map.insert("one", "foo");
    map.insert("two", "spam");
    map.find("one");
    // LRU is `two` now.
    map.insert("three", "bar");
    EXPECT_EQ(map.find("one"), "foo");
    EXPECT_EQ(map.find("two"), "");
    EXPECT_EQ(map.find("three"), "bar");
}

TEST(FixedSizeMap1, FindManyTimes)
{
    FixedSizeMap1 map(2);
    map.insert("one", "foo");
    map.insert("two", "spam");
    map.find("one");
    map.find("one");
}

TEST(FixedSizeMap2, InsertAndFind)
{
    FixedSizeMap2 map(1);
    map.insert("one", "foo");
    EXPECT_EQ(map.find("one"), "foo");
}

TEST(FixedSizeMap2, EraseAndFind)
{
    FixedSizeMap2 map(1);
    map.insert("one", "foo");
    map.erase("one");
    EXPECT_EQ(map.find("one"), "");
}

TEST(FixedSizeMap2, CapacityReached)
{
    FixedSizeMap2 map(1);
    map.insert("one", "foo");
    map.insert("two", "spam");
    EXPECT_EQ(map.find("one"), "");
    EXPECT_EQ(map.find("two"), "spam");
}

TEST(FixedSizeMap2, CapacityReachedLRURemoved)
{
    FixedSizeMap2 map(2);
    map.insert("one", "foo");
    map.insert("two", "spam");
    map.find("one");
    // LRU is `two` now.
    map.insert("three", "bar");
    EXPECT_EQ(map.find("one"), "foo");
    EXPECT_EQ(map.find("two"), "");
    EXPECT_EQ(map.find("three"), "bar");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
