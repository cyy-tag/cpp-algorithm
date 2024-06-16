#pragma once
#include <string>
#include <vector>
#include <functional>

using namespace std;
/*
 * LCS 最长公共子序列 有俩个字符串s和t
 * 子序列本质上就是选或不选 考虑最后一对字母 x 和 y
 * 总共有四种方案 1.选x和选y 2.选x和不选y  3.不选x和选y 4.不选x和不选y
 * 用dfs(i, j) 表示s的前i个字母和t的前j个字母的LCS长度
 * 按照四种选择方案有：
 * dfs(i,j) = max({dfs(i-1, j), dfs(i, j-1), dfs(i-1, j-1) + (s[i] == s[j])})
 * 简化
 * dfs(i, j) = dfs(i-1, j-1) + 1 s[i] == t[j](可以用反证法证明)
 * dfs(i, j) = max(dfs(i-1, j), dfs(i, j-1)) s[i] != t[j]
 */

/*1143.最长公共子序列*/
int longestCommonSubsequence_dfs(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> memo(m, vector<int>(n, -1));
    function<int(int, int)> dfs = [&](int i, int j) -> int {
        if(i < 0 || j < 0) {
            return 0;
        }
        int &val = memo[i][j];
        if(val != -1) {
            return val;
        }
        if(text1[i] == text2[j]) {
            return val = dfs(i-1, j-1) + 1;
        }

        return val = max(dfs(i-1, j), dfs(i, j-1));
    };

    return dfs(m-1, n-1);
}

/*递推形式*/
int longestCommonSubsequence_iterator(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> f(m+1, vector<int>(n+1, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(text1[i] == text2[j]) {
                f[i+1][j+1] = f[i][j] + 1;
            } else {
                f[i+1][j+1] = max(f[i][j+1], f[i+1][j]);
            }
        }
    }
    return f[m][n];
}

/*空间优化*/
//计算  f[i][j] = f[i-1][j-1](左上) + 1 (s[i] == t[j])
//      f[i][j] = max(f[i-1][j](上面), f[i][j-1](左边变量))
//      使用pre变量把左上变量记录起来, 优化空间成为一维的
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<int> f(n+1, 0);
    for(int i = 0; i < m; i++) {
        int pre = 0;
        for(int j = 0; j < n; j++) {
            int tmp = f[j+1];
            if(text1[i] == text2[j]) {
                f[j+1] = pre + 1;
            } else {
                f[j+1] = max(f[j+1], f[j]);
            }
            pre = tmp;
        }
    }
    return f[n];
}
