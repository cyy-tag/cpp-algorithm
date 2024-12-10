#pragma once
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

/*lis-longest increase sequence*/
// https://leetcode.cn/problems/longest-increasing-subsequence/

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n+1);
    for(int i = 1; i <= n; i++) {
        dp[i] = 1;
        for(int j = 1; j < i; j ++ ) {
            if(nums[j-1] < nums[i-1]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

void GetLengthOfLIS(vector<int>& nums) {
  int n = nums.size();
  vector<int> dp(n+1), g(n+1);
  for(int i = 1; i <= n; i++) {
    dp[i] = 1;
    g[i] = 0;
    for(int j = 1; j < i; j++) {
      if(nums[j-1] < nums[i-1]) {
        if(dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          g[i] = j;
        }
      }
    }
  }

  int k = 1;
  for(int i = 2; i <= n; i++) {
    if(dp[i] > dp[k]) {
      k = i;
    }
  }

  for(int i = 0, len = dp[k]; i < len; i++) {
    cout << g[k] << " ";
    k = g[k];
  }
}

//O(nlog(n))
//设d[l] 为长度l的上升子序列结尾最小元素
//贪心：同长度的子序列，结尾元素越小越有可能构成更长的序列
//初始值 d[0...n] = INF
//遍历原序列nums[i]，找到d中第一个大于等于nums[i](严格递增序列)， 并更新
int lengthOfLISBin(vector<int>& nums) {
    int n = nums.size();
    vector<int> d(n, numeric_limits<int>::max());
    for(int & num : nums) {
        int l = lower_bound(d.begin(), d.end(), num) - d.begin();
        d[l] = num;
    }

    int ans = 0;
    for(int i = n - 1; i >= 0; --i) {
        if(d[i] < numeric_limits<int>::max()) {
            ans = i + 1;
            break;
        }
    }
    return ans;
}
