#pragma once
#include <algorithm>
#include <vector>

/*
  第二类斯特林数：S(n, k) 表示将n个俩俩不同的元素，划分为k
  个互不区分的非空字集的方案数

  性质：
    1.当 n < k时， S(n, k) = 0, 因为不能将少于k的元素划分成k个集合
    2.当 n >= 1 时，S(n, 1) == 1, 只有一种方式将所有的元素放入一个集合中
    3.S(i, k) = S(i-1, k-1) + k*S(i-1, k)
      讨论第i个人怎么划分
        1.将第i个人单独放入一个子集，有S(i-1, k-1)方案
        2.将第i个人放入前面的k个集合中，有k*S(i-1, k)方案
*/

int StirlingNumberSecondKind(int n, int m) {
    // 创建一个二维数组，初始化为0
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    //初始化
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= std::min(i, m); ++j) {
            dp[i][j] = dp[i - 1][j - 1] + j * dp[i - 1][j];
        }
    }
    return dp[n][m];
}
