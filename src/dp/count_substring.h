#pragma once
#include <string>
#include <vector>

/*
  求字符串s的全部子串的数量, s的长度为n S = n(n+1) / 2
  对于每个可能的子串长度k(从1到n), 字符串可以被分割成n-k+1个长度为k的子串
  对于长度为1，有n个子串
  对于长度为2，有n-1个子串
  ...
  是一个等差数列求和过程 S = n*(n+1) / 2
*/

/*
  一串字符串求子串的数量
  求给定字符串s的不同子串组成的数量
  令dp[i]代表的是以i-1为结尾的不同的子串的个数(i >= 1)
  初始状态dp[0] = 0;
  用last[s[i]] 表示上一个s[i]的位置
  当遍历到i时有俩种状态：
    1.之前还没有遇到s[i-1]字符 dp[i] = 2*d[i-1] + 1; 这里的1为s[i-1]本身构成新的子串
    2.当s[i-1]出现过, dp[i] 相对于dp[i-1]多了一倍，其中对于[1, last[s[i]]]中的状态会重复
      计算需要减掉，即：dp[i] = 2*dp[i-1] - dp[last[s[i]]]
*/

//https://leetcode.cn/problems/distinct-subsequences-ii/description/
int DistinctSubseq(const std::string& s)
{
  int n = s.size();
  std::vector<int> dp(n+1);
  std::vector<int> last(26, -1); //只有小写字母
  dp[0] = 0;
  int mod = 1e9+7;
  for(int i = 1; i <= n; i++) {
    int index = s[i-1] - 'a';
    if(last[index] == -1) dp[i] = (2*dp[i-1] + 1) % mod;
    else dp[i] = ((long long)2*dp[i-1] - dp[last[index]] + mod) % mod;
    last[index] = i - 1;
  }
  return dp[n];
}
