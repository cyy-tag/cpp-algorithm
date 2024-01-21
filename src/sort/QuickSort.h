#pragma once
#include <vector>

template<typename T>
int Partition(std::vector<T>& nums, int lo, int hi)
{
    int i = lo, j = hi + 1;
    T pivot = nums[lo];
    while(true){
        while(nums[++i] < pivot) if(i == hi) break;
        while(pivot < nums[--j]);
        if(i >= j) break;
        std::swap(nums[i], nums[j]);
    }
    std::swap(nums[j], nums[lo]);
    return j;
}

template<typename T>
void QuickSort(std::vector<T>& nums, int lo, int hi)
{
    if(hi <= lo)
        return;
    size_t mid = Partition(nums, lo, hi);
    QuickSort(nums, lo, mid-1);
    QuickSort(nums, mid+1, hi);
}
