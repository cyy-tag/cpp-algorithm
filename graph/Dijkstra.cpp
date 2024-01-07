#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

std::vector<std::vector<std::pair<int,int>>> adj;

//force
void dijkstra(int n, int src) {
    std::vector<int> vis(n, 0);
    std::vector<int> dst(n, std::numeric_limits<int>::max());
    dst[src] = 0;
    for(int i = 0; i < n; ++i)
    {
        int u = 0, mind = std::numeric_limits<int>::max();
        for(int j = 0; j < n; ++j)
        {
            if(!vis[j] && dst[j] < mind)
            {
                u = j;
                mind = dst[j];
            }
        }

        vis[u] = true;
        for(auto edge : adj[u])
        {
            int v = edge.first, we = edge.second;
            if(dst[v] > dst[u] + we)
            {
                dst[v] = dst[u] + we;
            }
        }
    }
}


//priority_queue
void dijkstra(int s, std::vector<int>& dst)
{
    std::fill(dst.begin(), dst.end(), std::numeric_limits<int>::max());
    std::size_t n = adj.size();
    dst[s] = 0;
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> q;
    q.emplace(0, s);
    std::vector<int> vis(n, 0);
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto ed : adj[u]) {
            int next = ed.first, we = ed.second;
            if(dst[next] > dst[u] + we) {
                dst[next] = dst[u] + we;
                q.emplace(dst[u]+we, next);
            }
        }
    }
}
