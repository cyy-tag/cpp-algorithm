#pragma once
#include <vector>
#include <functional>

using namespace std;
/*
0-1背包: 有n个物品，第i个物品的体积为w[i]
价值为v[i]，每个物品至多选一个，求体积和不超过
capacity时的最大值和

当前操作 当前容量为c, 枚举第i个物品选或不选
dfs(i, c) = max(dfs(i-1, c), dfs(i-1, c - w[i])+v[i])
*/

//回溯
/*
 @brief capacity: 背包容量
 w[i]: 第 i 个物品的体积
 v[i]: 第 i 个物品的价值
 返回: 所选物品体积和不超过 capacity 的前提下，所能得到的最大价值和
*/
int zero_one_packet_recursion(int capacity, vector<int>& w, vector<int>& v) {
    int n = w.size();
    vector<vector<int>> memo(n, vector<int>(capacity, -1));
    function<int(int,int)> dfs = [&](int i, int c) -> int {
        if(i < 0) {
            return 0;
        }

        int &val = memo[i][c];
        if(val != -1) {
            return val;
        }

        if(c < w[i]) {
            return val = dfs(i-1, c);
        }
        return val = max(dfs(i-1, c), dfs(i-1, c-w[i])+v[i]);
    };

    dfs(n-1, capacity);
}

//递推
//f[i+1][c] = f[i][c] + f[i][c-x] (c > x)
int zero_one_iter(int capacity, vector<int>& w, vector<int>& v) {
    vector<int> f(capacity+1);
    f[0] = 1;
    for(int num : w) {
        for(int c = capacity; c >= num; c--) {
            f[c] = f[c] + f[c - num];
        }
    }
    return f[capacity];
}
