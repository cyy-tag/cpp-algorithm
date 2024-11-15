#pragma once
/* The maximum of any subarray sum absolute value */

/*
  prefix sum: prefix_sum[i] = prefix_sum[i-1] + arr[i];
  sum(arr[i+1]...arr[j]) sum = prefix_sum[j] - prefix_sum[i]

  max prefix: max_prefix = max(max_prefix, prefix_sum[i])
  min prefix: min_prefix = min(min_prefix, prefix_sum[i])

  max_abs_sum = max(max_abs_sum, abs(prefix_sum[j] - max_prefix), abs(prefix_sum[j] - min_prefix))
*/

int maxAbsoluteSum(vector<int>& nums) {
    int max_pre = 0, min_pre = 0;
    int pre_sum = 0;
    int ans = 0;
    for(int num : nums) {
        pre_sum += num;
        ans = max({ans, abs(pre_sum - max_pre), abs(pre_sum - min_pre)});
        max_pre = max(max_pre, pre_sum);
        min_pre = min(min_pre, pre_sum);
    }
    return ans;
}
