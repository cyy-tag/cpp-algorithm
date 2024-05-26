#pragma once
#include <iostream>
#include <unordered_map>
//统计因子(枚举因子) 和 枚举倍数

using namespace std;

//求x的所有因子
unordered_map<int,int> find_div(int x) {
    unordered_map<int,int> cnt;
    for(int d = 1; d * d <= x; d++) {
        if(x % d) {
            continue;
        }
        cnt[d]++; // a * d = x
        // 对 d * d = x 的情况去重, d 只记录一次
        if( d * d < x) {
            cnt[x / d]++;
        }
    }
    return cnt;
}

//求[x, u] 范围内x的所有倍数
unordered_map<int,int> find_mul(int x, int u) {
    unordered_map<int,int> cnt;
    for(int j = x; j <= u; j += x) {
        cnt[j]++;
    }
    return cnt;
}
