#pragma
#include <vector>
/*
 * 分解质因数 
 * https://oi-wiki.org/math/number-theory/pollard-rho/
 * 反证法证明，若res存在非质数k, 那么存在数j 是k的因子
 * 那么j也是N的一个因子, 而当循环到K时, N不被任何小于K的i整除互相矛盾
 */

//朴素做法
/*求N的所有质因子*/
std::vector<int> DecomposePrimeFactor(int N) {
  std::vector<int> res;
  for(int i = 2; i * i <= N; ++i) {
    if(N % i == 0) {
      while(N % i == 0) N /= i;
      res.push_back(i);
    }
  }

  if(N > 1) {
    res.push_back(N);
  }
  return res;
}

/*
质因子重排计数构造
https://codeforces.com/problemset/problem/1881/D
*/


/*
 * 其他快速求质因子的算法
 */
