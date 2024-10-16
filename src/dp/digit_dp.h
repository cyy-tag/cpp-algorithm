#pragma once
#include <string>

using namespace std;

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
