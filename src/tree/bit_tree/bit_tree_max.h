#pragma once
#include <vector>
#include <numeric>

using namespace std;

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
