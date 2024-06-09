#include <numeric>
#include <ctime>
#include <random>
#include <gtest/gtest.h>
//gcd tesst
#include "gcd.h"
//qmi test
#include "binary_exponentiation.h"

class MathTest : public testing::Test {
protected:
  void SetUp() override {
    r_.seed(time(0));
  }
  std::default_random_engine r_;
};

TEST_F(MathTest, Gcd) {
  for(int  i = 0; i < 3; i++) {
    int a = r_(), b = r_();
    ASSERT_EQ(std::gcd(a, b), gcd_general(a, b));
    ASSERT_EQ(std::gcd(a, b), gcd_division(a, b));
  }
}

TEST_F(MathTest, QMI) {
  int a = 2;
  for(int i = 0; i < 3; i++) {
    int b = r_() % 63;
    ASSERT_EQ((long long)std::pow(a, b), BinPow(a, b));
  }
}
