#pragma once
#include <cmath>
/* 
 * 欧拉函数(Euler's totient function) φ(n)
 * 表示小于等于n和n互质的个数
 * φ(1) = 1
 * 特别的当n为质数的时候，显然有φ(n) = n - 1
 */

int euler_phi(int n) {
  int ans = n;
  for(int i = 2; i * i <= n; i++) {
    if(n % i == 0) {
      ans = ans / i * (i - 1);
      while(n % i == 0) n /= i;
    }
  }
  if(n > 1) ans = ans / n*(n-1);
  return ans;
}
