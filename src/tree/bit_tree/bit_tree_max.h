#pragma once
#include <vector>
#include <numeric>

using namespace std;

//全局最值
class BitTreeMax
{
private:
  int n_;
  vector<int> bit_;
public:
  explicit BitTreeMax(int n): n_(n), bit_(n+1, numeric_limits<int>::min()/2) {}

  int lowbit(int x) noexcept {
    return x & -x;
  }

  void update(int index, int val) {
    for(int i = index; i <= n_; i += lowbit(i)) {
      bit_[i] = max(bit_[i], val);
    }
  }

  int query(int index) {
    int ans = numeric_limits<int>::min()/2;
    for(int i = index; i > 0; i -= lowbit(i)) {
      ans = max(ans, bit_[i]);
    }
    return ans;
  }
};


//区间最值
class BitTreeIntervalMax
{
private:
  int n_;
  vector<int> bit_; //bittree
  vector<int> arr_; //单点存储值大小
public:
  BitTreeIntervalMax(int n)
   : n_(n),
     bit_(n+1, numeric_limits<int>::min()),
     arr_(n+1, numeric_limits<int>::min())
  {}

  int lowbit(int x) { return x & -x; }

  void update(int idx, int v) {
    arr_[idx] = v; //更新单点值
    while(idx <= n_) {
      bit_[idx] = max(bit_[idx], v);
      idx += lowbit(idx);
    }
  }

  //求区间[start, end] 的最值
  int query(int start, int end) {
    int ans = numeric_limits<int>::min();
    while(end >= start) {
      //当bit中的end位置保留区间范围不超过start时就用bit的值
      if(end-lowbit(end) >= start) {
        ans = max(ans, bit_[end]);
        end -= lowbit(end);
      } else {
        //否则使用原始的每个位置
        ans = max(ans, arr_[end]);
        end--;
      }
    }
    return ans;
  }
};
