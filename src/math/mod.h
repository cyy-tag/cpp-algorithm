#pragma
/*
 * 加法取模
 * (a + b) mod m = ((a mod m) + (b mod m)) mod m
 * 证明推导：设 a = q1m + r1 b = q2m + r2
 *          那么(a + b) mod m = (q1m + r1 + q2m + r2) mod m
 *                            = (r1 + r2) mod m
 *                            = ((a mod m) + (b mod m)) mod m
 * 
 * 乘法取模
 * (a*b) mod m = ((a mod m) * (b mod m)) mod m
 * 证明推导：设 a = q1m + r1 b = q2m + r2
 *          那么(a*b) mod m = ((q1m + r1)*(q2m + r2)) mod m
 *                          = (q1q2m^2 + 2*q1m*q2m + r1*r2) mod m
 *                          = (r1*r2) mod m
 *                          =((a mod b) * (b mod m)) mod m
 * 指数运算
 * a^(b) mod m = (a mod m)^b mod m
 * 展开推导 a^(b) mod m = (a * a * .... * a) mod m
 *                     = (a mod m) * (a mod m) * (a mod m) * ... * (a mod m)
 *                     = (a mod m) ^ b
 * 
 * 负数（减法）取模
 * 如果x和y均为非负整数，且 x mod m = y mod m
 * 如果x < 0, y >= 0, 则 x mod m + m = y mod m
 * 
 * 除法取模-转换成乘法
 * 结论: 如果p是一个指数， a是b的倍数且b和p互质（b 不是 p的倍数），那么有
 * a/b mod p = (a * b^(p -2)) mod p (可以用快速幂处理)
 * 详细证明地址：https://leetcode.cn/circle/discuss/mDfnkW/
 * 处理阶乘和逆元的模板
 */
  const int MOD = 1'000'000'007;
  const int MX = 41;

  long long F[MX]; // F[i] = i!
  long long INV_F[MX]; // INV_F[i] = i!^-1

  long long pow(long long x, int n) {
      long long res = 1;
      for (; n; n /= 2) {
          if (n % 2) {
              res = res * x % MOD;
          }
          x = x * x % MOD;
      }
      return res;
  }

  auto init = [] {
      F[0] = 1;
      for (int i = 1; i < MX; i++) {
          F[i] = F[i - 1] * i % MOD;
          INV_F[i-1] = pow(F[i-1], MOD-2);
      }
      return 0;
  }();

/*
 * 扩展欧拉定理--降幂
 * 欧拉函数(Euler's totient function)， u(n) 表示的是小于等于n和n互质的个数。
 * 当遇到指数运算，指数过大时可以使用拓展欧拉定理降幂
 * https://oi-wiki.org/math/number-theory/fermat/#%E6%89%A9%E5%B1%95%E6%AC%A7%E6%8B%89%E5%AE%9A%E7%90%86
 */

/*
  n为负数情况处理
  https://leetcode.cn/problems/powx-n/description/

  乘法取模
  https://leetcode.cn/problems/double-modular-exponentiation/description/
  https://leetcode.cn/problems/count-collisions-of-monkeys-on-a-polygon/

  指数取模
  https://leetcode.cn/problems/super-pow/
*/
