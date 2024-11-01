#pragma once
#include <vector>

class UnionFind
{
public:
  UnionFind(int v)
    :parent_(v), rank_(v, 1)
  {
    for(int i = 0; i < v; i++) {
      parent_[i] = i;
    }
  }

  int Find(int v) {
    if(parent_[v] != v) {
      return Find(parent_[v]);
    }
    return v;
  }

  void Union(int v, int q) {
    int v_parent = Find(v);
    int q_parent = Find(q);
    if(v_parent == q_parent) {
      return;
    }

    if(rank_[v_parent] > rank_[q_parent]) {
      parent_[q_parent] = v_parent;
      rank_[v_parent] += rank_[q_parent];
    } else {
      parent_[v_parent] = q_parent;
      rank_[q_parent] += rank_[v_parent];
    }
  }

  int Size(int x) {
    return rank_[Find(x)];
  }

private:
  std::vector<int> parent_, rank_;
};
