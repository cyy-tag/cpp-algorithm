//树状数组
//作用于单点修改和区间查询的数据结构
#include <vector>
using namespace std;

class BitTree
{
private:
    int n_;
    vector<int> bit_;
public:
    BitTree(int n): n_(n), bit_(n+1) {
    }

    int lowbit(int x) {
        return x & -x;
    }
    //x>0
    void add(int x, int c) {
        for(int i = x; i <= n_; i+=lowbit(i)) {
            bit_[i] += c;
        }
    }

    int query(int x) {
        if(x == 0) {
            return 0;
        }
        int res = 0;
        for(int i = x; i; i -= lowbit(i)) {
            res += bit_[i];
        }
        return res;
    }

    //查询区间和[l, r]
    int query(int l, int r) {
        if(r < l) {
            return 0;
        }
        return query(r) - query(l-1);
    }
};
