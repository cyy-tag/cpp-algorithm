#include <vector>
#include <iostream>

template<typename T>
T Partition(std::vector<T>& nums, int lo, int hi)
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
    int mid = Partition(nums, lo, hi);
    QuickSort(nums, lo, mid-1);
    QuickSort(nums, mid+1, hi);
}

int main(int argc, char*argv[])
{
    std::vector<int> nums{50, 1, 2, 3, 10, 22, 12, 23, 42, 12};
    QuickSort(nums, 0, nums.size()-1);
    for(auto num : nums){
        std::cout << num << std::endl;
    }
    std::vector<float> nums_flost{1.2, 2.3, 10.2, 230.2, 1.23};
    QuickSort(nums_flost, 0, nums_flost.size()-1);
    for(auto num : nums_flost) {
        std::cout << num << std::endl;
    }
    return 0;
}

