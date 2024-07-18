#include "Dijkstra.h"
#include <gtest/gtest.h>


class DijkstraTest : public testing::Test {
protected:
  void SetUp() override {
      n_ = 3;
      edges_.push_back({0,1,2});
      edges_.push_back({1,2,1});
      edges_.push_back({0,2,4});
      result_ = std::vector<int>{0,2,3};
  }

  int n_;
  std::vector<std::vector<int>> edges_;
  std::vector<int> result_;
};

TEST_F(DijkstraTest, TestDisk) {
  Dijkstra disk;
  disk.CreateGraph(n_, edges_);
  auto ret = disk.Calculate(0);
  ASSERT_EQ(ret.size(), result_.size());
  for(int i = 0; i < ret.size(); i++)
  {
    ASSERT_EQ(ret[i], result_[i]);
  }
  disk.ShowShortPath(0);
}
