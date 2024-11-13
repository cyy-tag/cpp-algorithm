#pragma once
#include <string>
int a[20];

void convert(long long num) {
    int len = 0;
    while(num) {
        a[++len] = num % 10;
        num /= 10;
    }
    //转换成十进制格式
}

using namespace std;
// 返回从i 开始填数字, i 前面填的数字的集合是mask, 能构造出的特殊整数的数目
// is_limit 表示前面填的数字是否都是n对应位上的, 如果为true，那么当前位至多为 int(s[i]), 否则至多为 9
// is_num 表示前面是否填了数字(是否跳过), 如果为true, 那么当前位可以从0开始
// 如果为false，那么我们可以跳过，或者从1开始填数字

int CountSpecialNumbers(int n) {
    auto s = to_string(n);
    int m = s.length(), dp[m][1 << 10];
    memset(dp, -1, sizeof(dp));
    function<int(int, int, bool, bool)> f = [&](int i, int mask, bool isLimit, bool isNum) -> int {
        if(i == m) return isNum;
        if(!isLimit && isNum && dp[i][mask] >= 0) return d[i][mask];
        int res = 0;
        if(!isNum) res = f(i+1, mask, false, false); //可以跳过当前数
        for(int d = 1 - isNum, up = isLimit ? s[i] - '0' : 9; d <= up; ++d) //枚举要填入的数字d
        {
            if ((mask >> d & 1) == 0) { // d不在mask中
                res += f(i+1, mask | (1 << d), isLimit && d == up, true);
            }
        }

        if(!isLimit && isNum) dp[i][mask] = res;
        return res;
    };
    return f(0, 0, true, false);
}

/*题目
 * L, R 求在[L, R]范围内符合条件的个数 ans = f(R) - f(L-1)
 * https://codeforces.com/problemset/problem/1036/C
 * 
 * 求后缀符合条件的个数, 后序遍历
 * https://codeforces.com/problemset/problem/507/D
 * 
 * 全局记忆化, 状态压缩, 全局记忆化需要特判 !is_limit和isNum前导零, 以及位数记忆化下标要从低位到高
 * https://codeforces.com/contest/855/problem/E
 * 
 * // 位上计数、求和 [L, R]范围
 * https://www.luogu.com.cn/problem/AT_abc029_d
 * https://www.luogu.com.cn/problem/P2602
 * https://www.luogu.com.cn/problem/P4999
 * 
 * 在给定范围查找[l, r] 第K个符合条件的 二分答案 + 数位dp
 * https://www.luogu.com.cn/problem/AT_arc173_a
 * 
 * 统计回文串个数
 * https://www.luogu.com.cn/problem/B3883
 * 
 * 