#include <numeric>
#include <ctime>
#include <random>
#include <gtest/gtest.h>
//gcd tesst
#include "gcd.h"

class MathTest : public testing::Test {
protected:
  void SetUp() override {
    r_.seed(time(0));
  }
  std::default_random_engine r_;
};

TEST_F(MathTest, Gcd) {
  for(int  i = 0; i < 10; i++) {
    int a = r_(), b = r_();
    ASSERT_EQ(std::gcd(a, b), gcd_general(a, b));
    ASSERT_EQ(std::gcd(a, b), gcd_division(a, b));
  }
}
