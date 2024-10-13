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
