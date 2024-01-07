#include <vector>
#include <algorithm>

void Floyd(int n, std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<int>> f(n, std::vector<int>(n, 10005));
    //initialize
    for(auto& edge : edges)
    {
        int from = edge[0], to = edge[1];
        int we = edge[2];
        f[from][to] = f[to][from] = we;
    }

    for(int k = 0; k < n; ++k) {
        f[k][k] = 0;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                f[x][y] = std::min(f[x][y], f[x][k] + f[k][y]);
            }
        }

    }
}
