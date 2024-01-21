#pragma once
#include <vector>

template<typename T>
void BubbleSort(std::vector<T>& nums)
{
    int n = nums.size();
    for(int i = 0; i < n; ++i)
    {
        for(int j = n - 1; j > i; --j)
        {
            if(nums[j] < nums[j-1])
                std::swap(nums[j], nums[j-1]);
        }
    }
}
