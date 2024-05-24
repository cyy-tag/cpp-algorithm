#pragma once
/*
(Greatest Common Divisor)最大公约数
俩个数a和b的最大公约数,是指同时整除a和b的最大因子,记为gcd(a, b)。
当gcd(a, b) = 1，称a和b互素
*/

/*
朴素法求公约数
直接遍历,判断每个数是否可以被a和b整除
O(n)时间复杂度
*/

int gcd_general(int a, int b) {
  for(int i = a; i >= 2; i--) {
    if(a % i == 0 && b % i == 0) {
      return i;
    }
  }
  return 1;
}

/*
辗转相除法
gcd(a, b) = gcd(b, a mod b)
*/
int gcd_division(int a, int b) {
  return !b ? a : gcd_division(b, a %  b);
}
