#pragma once
#include <numeric>
/*
 * 快速幂，二进制取幂，是一个在O(logn)的时间内计算 pow(a, n)的技巧
 * pow(a, b+c) = pow(a, b) * pow(a, c)
 * pow(a, 21(b10101)) = pow(a, 16(b10000)) * pow(a, 4(100)) * pow(a, 1(b1))
 * 按照二进制的方式分割成更小的任务。
 * 当n < 0的情况 
 * 把 n 变为 -n, 把x变成 1/x 成为 x^(-n) = (1/x)^(-n)
 */

static long long BinPowMod(long long a, long long b, long long mod) {
    long long res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b = b >> 1;
    }
    return res;
}

static long long BinPow(long long a, long long b) {
    return BinPowMod(a, b, std::numeric_limits<long long>::max());
}
