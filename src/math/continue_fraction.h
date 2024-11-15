#pragma once
#include <vector>
//p/q 有理数连分数构造, 构造唯一最后一项非1
/*
  a1 = [p/q] + 1/x (r0 = p - a0*q = p % q 为小数部分）
  令a1 为 p/q的整数部分, 若a1等于0，那么p/q整数
  小数部分表示：1/x = p%q / q
  考虑a2时, 实际考虑的分数变为(q, p%q)

  考虑最后一项形式为1/rn
  其中rn是通过减去一个整数乘积得到的，必须是一个小于1的正数,
  如果最后一项的分母为1，那么它将是一个整数，这于连分数的定义相矛盾

*/

std::vector<int> ContinueFraction(int p, int q) {
  vector<int> continue_fraction;
  while(q) {
    continue_fraction.push_backk(p/q);
    p %= q;
    swap(p, q);
  }
  return continue_fraction;
}
