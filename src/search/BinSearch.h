#pragma once
#include <vector>

//nums is sorted in asscending order
template<typename T>
int BinSearch(std::vector<T>& nums, const T target)
{
    int left = 0, right = nums.size()-1;
    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

template<typename T>
int LowerBound(std::vector<T>& nums, const T target)
{
    int left = 0, right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if(nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

template<typename T, typename Cmp>
int LowerBound(std::vector<T>& nums, const T target, Cmp cmp)
{
    int left = 0, right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if(cmp(nums[mid], target)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
