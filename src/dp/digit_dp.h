#pragma once
#include <string>

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
