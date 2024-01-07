#include <vector>
#include <limits>
#include <queue>

int ShortestPath(int n, int src, int dst, std::vector<std::vector<int>>& edges) {
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    dist[src] = 0;
    while(true)
    {
        bool any = false;
        for(auto & edge : edges) {
            int from = edge[0], to = edge[1];
            int weight = edge[2];
            if (dist[from] < std::numeric_limits<int>::max()) {
                if (dist[to] > dist[from] + weight) {
                    dist[to] = dist[from] + weight;
                    any = true;
                }
            }
        }
        if (!any) {
            break;
        }
    }
    return dist[dst] == std::numeric_limits<int>::max() ? -1 : dist[dst];
}

//spsa
bool ShortestPath(int src, std::vector<std::vector<std::pair<int,int>>>& adj) {
    std::size_t n = adj.size();
    std::vector<int> cnt(n, 0);
    //1.定义一个距离数组dist
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    //2.增加队列
    std::queue<int> q;
    //3.增加数组判断当前顶点是否存在队列中
    std::vector<int> inqueue(n, 0);
    //4.初始化开始点src
    dist[src] = 0;
    q.push(src);
    inqueue[src] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)
                        return false;
                }
            }
        }
    }
    return true;
}
