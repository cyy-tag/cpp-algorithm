#pragma once
#include <vector>
#include <function>
/* 滑动窗口
 * 把[l, r] 称为一个【窗口】
 * 1.r+1 扩大窗口
 * 2.判断窗口条件, 增加l，直到窗口满足条件
 * 3.再根据当前[l, r]窗口计算答案
 * 4.重复1-3过程直到结束
 */

using namespace std;

void SlidingWindow(vector<int>& nums, function<bool(int, int)> check) {
    int l = 0, cnt = 0;
    int n = nums.size();
    //1.r+1扩大窗口
    for(int r = 0; r < n; r++) {
        //当前窗口的个数
        cnt++;
        //2.判断不断增加l直到[l, r]满足条件
        while(!check(nums[l], nums[r])) {
            ++l;
        }

        //3.计算结果
    }
}
