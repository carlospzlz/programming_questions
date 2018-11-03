#include "find_kth_largest.h"
#include "gtest/gtest.h"
#include <vector>
#include <iostream>

void print(const std::vector<int>& v)
{
    for (auto x : v)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

TEST(FindKthLargest, Partition1)
{
    Solution solution;
    std::vector<int> v{3, 2, 1, 5, 4};
    solution.partition(v, 0, 4);
    std::vector<int> expected({1, 2, 3, 5, 4});
    ASSERT_EQ(v, expected);
}

TEST(FindKthLargest, findKthLargest1)
{
    Solution solution;
    std::vector<int> v{3, 2, 1, 5, 6, 4};
    int result = solution.findKthLargest(v, 2);
    ASSERT_EQ(result, 5);
}

TEST(FindKthLargest, findKthLargest2)
{
    Solution solution;
    std::vector<int> v{3, 2, 3, 1, 2, 4, 5, 5, 6};
    int result = solution.findKthLargest(v, 4);
    ASSERT_EQ(result, 4);
}

TEST(FindKthLargest, findKthLargest3)
{
    Solution solution;
    std::vector<int> v{2, 1};
    int result = solution.findKthLargest(v, 1);
    ASSERT_EQ(result, 2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
