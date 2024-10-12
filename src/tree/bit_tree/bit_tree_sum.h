#pragma once
//bit tree sum
#include <vector>
using namespace std;

class BitTreeSum
{
private:
    int n_;
    vector<int> bit_;
public:
    explicit BitTreeSum(int n): n_(n), bit_(n+1) {
    }

    int lowbit(int x) noexcept {
        return x & -x;
    }
    //x>0
    void add(int x, int c) noexcept {
        for(int i = x; i <= n_; i+=lowbit(i)) {
            bit_[i] += c;
        }
    }

    int query(int x) noexcept {
        int res = 0;
        for(int i = x; i; i -= lowbit(i)) {
            res += bit_[i];
        }
        return res;
    }

    // sum[l, r]
    int query(int l, int r) noexcept {
        if(r < l) {
            return 0;
        }
        return query(r) - query(l-1);
    }
};
