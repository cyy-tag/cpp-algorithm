#pragma once
/*
  排列组合
*/
/*
  C(n, m) = C(n, n - m)
  C(n, m) = n * (n - 1) * (n - 2) * (n  - m + 1) / m!
  C(n, n - m) = n * (n - 1) * (m+1)/(n-m)!
*/
long long C(int n, int m)
{
	if (m < n - m) m = n - m;
	long long ans = 1;
	for (int i = m + 1; i <= n; i++) ans *= i;
	for (int i = 1; i <= n - m; i++) ans /= i;
	return ans;
}

/*
 * 组合数预处理C(a, b) = C(a-1, b-1) + C(a-1, b) 
 * 在a集合中取b个 以取不取第b个分类讨论
 *  取第b个，那么在剩余a-1中取b-1个
 *  不取第b个，那么在剩余a-1中取b个
 */
const int N = 35;
int f[N][N];
void init() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= i; j++) {
      if(!j) f[i][j] = 1; //C(i, 0)
      else f[i][j] = f[i-1][j] + f[i-1][j-1];
    }
  }
}

/*
  A(n, m) = n*(n-1)*(n-2)*(n - m + 1) = n!/(n-m)!
*/

long long A(int n, int m)
{
  long long ans = 1;
  for(int i = n; i >= (n - m + 1); --i) {
    ans *= i;
  }
  return ans;
}
