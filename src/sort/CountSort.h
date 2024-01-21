#pragma once
#include <vector>

void CountSort(std::vector<int>& nums, int max_val, int min_val)
{
    size_t n = nums.size();
    int range = max_val - min_val + 1;
    std::vector<int> count(range, 0);
    std::vector<int> ans(n, 0);
    //count
    for(auto num : nums) {
        count[num - min_val]++;
    }
    //calculate pos
    for(int i = 1; i < range; ++i)
    {
        count[i] += count[i-1];
    }
    //put val
    for(int i = 0; i < n; ++i)
    {
        ans[count[nums[i] - min_val] - 1] = nums[i];
        count[nums[i] - min_val]--;
    }
    nums = ans;
}
