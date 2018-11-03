#include "find_kth_largest.h"
#include <utility>
#include <iostream>

int Solution::findKthLargest(std::vector<int>& nums, int k)
{
    k = nums.size() - k;
    int lo = 0;
    int hi = nums.size() - 1;
    while (lo < hi)
    {
        int j = partition(nums, lo, hi);
        if (j < k)
        {
            lo = j + 1;
        }
        else if (j > k)
        {
            hi = j - 1;
        }
        else
        {
            break;
        }
    }
    return nums[k];
}

int Solution::partition(std::vector<int>& nums, int lo, int hi)
{
    int i = lo;
    int j = hi + 1;
    int pivot = nums[lo];
    while (true)
    {
        while (i < hi && nums[++i] < pivot);
        while (j > lo && nums[--j] > pivot);
        if (i >= j)
        {
            break;
        }
        std::swap(nums[i], nums[j]);
    }
    std::swap(nums[lo], nums[j]);
    return j;
}
