#pragma once
#include <vector>
#include <queue>

//bfs

int LongestPathBfs(std::vector<std::vector<int>>& graph)
{
    int n = graph.size();
    int ans = 0;
    std::vector<int> visis(n);
    for(int i = 0; i < n; i++) {
        std::fill(visis.begin(), visis.end(), 0);
        int cnt = 0;
        visis[i] = true;
        std::queue<int> q;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ++cnt;
            for(int next : graph[node]) {
                if(visis[next]) {
                    continue;
                }
                visis[next] = true;
                q.push(next);
            }
        }
        ans = std::max(ans, cnt);
    }
    return ans;
}
