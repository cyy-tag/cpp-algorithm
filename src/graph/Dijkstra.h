#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <iostream>

/// @brief Dijkstra 主要用来解决最短路径问题 -- 无环图

std::vector<std::vector<std::pair<int,int>>> adj;

//暴力解法
void dijkstra(int n, int src) {
    std::vector<int> vis(n, 0);
    std::vector<int> dst_(n, std::numeric_limits<int>::max());
    dst_[src] = 0;
    for(int i = 0; i < n; ++i)
    {
        int u = 0, mind = std::numeric_limits<int>::max();
        for(int j = 0; j < n; ++j)
        {
            if(!vis[j] && dst_[j] < mind)
            {
                u = j;
                mind = dst_[j];
            }
        }

        vis[u] = true;
        for(auto edge : adj[u])
        {
            int v = edge.first, we = edge.second;
            if(dst_[v] > dst_[u] + we)
            {
                dst_[v] = dst_[u] + we;
            }
        }
    }
}

//优先队列解法
class Dijkstra
{
public:
  /// @brief 创建领接矩阵
  /// @param n 节点数量，编号(0, n-1)
  /// @param edges 节点之间的边和权重 [n0, n1, wegiht]
  void CreateGraph(int n, std::vector<std::vector<int>> edges)
  {
    n_ = n;
    adj_.resize(n);
    for(auto & edge : edges) {
      adj_[edge[0]].emplace_back(edge[1], edge[2]);
      adj_[edge[1]].emplace_back(edge[0], edge[2]);
    }
  }

  /// @brief 计算节点v到其他节点的最小路径值
  /// @param v 节点v
  /// @return 返回dst_ dst_[i] 表示节点v到i的最小路径值, -1表示不可达
  std::vector<int> Calculate(int v)
  {
    dst_.resize(n_);
    std::fill(dst_.begin(), dst_.end(), -1);
    pre_.resize(n_);
    std::fill(pre_.begin(), pre_.end(), -1);
    std::vector<int> vis(n_, 0);
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> q;
    dst_[v] = 0;
    q.emplace(0, 0);
    while(!q.empty()) {
      auto [weight, node] = q.top();
      q.pop();
      if(vis[node]) {
        continue;
      }
      vis[node] = true;

      for(auto [next, w] : adj_[node]) {
        if(dst_[next] == -1 || dst_[next] > weight + w) {
          dst_[next] = weight + w;
          pre_[next] = node;
          q.emplace(weight+w, next);
        }
      }
    }

    return dst_;
  }

  /// @brief 打印节点v 到各个点的最短路径
  /// @param v 起点v
  void ShowShortPath(int v)
  {
    Calculate(v);
    
    for(int i = 0; i < n_; i++) {
      if(dst_[i] == -1 || dst_[i] == 0) {
        //源点和不可达终点
        continue;
      }
      std::cout << "源点 " << v << " 到 " << i << "的最短路径为: " << std::endl;

      int t = pre_[i];
      std::stack<int> st;
      while(t != v) {
        st.push(t);
        t = pre_[t];
      }

      std::cout << v;
      while(!st.empty()) {
        std::cout << " --> " << st.top();
        st.pop();
      }
      std::cout << " --> " << i << std::endl;
    }
  }

private:
  int n_;
  std::vector<int> pre_; //保存最小路径的前驱
  std::vector<int> dst_; //保存节点v到其他节点的最小路径值
  std::vector<std::vector<std::pair<int,int>>> adj_;//领接矩阵表示
};
