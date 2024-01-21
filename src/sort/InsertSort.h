#pragma once
#include <vector>

template<typename T>
void InsertSort(std::vector<T>& nums)
{
    for(int i = 1; i < nums.size(); ++i)
    {
        if(nums[i] >= nums[i-1])
            continue;
        int j = i-1;
        while(j >= 0 && nums[j] > nums[j+1]) {
            std::swap(nums[j], nums[j+1]);
            --j;
        }
    }
}
