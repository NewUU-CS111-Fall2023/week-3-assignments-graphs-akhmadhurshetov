/*
 * Author: Axmad Xurshetov
 * Date: 31.10.2023
 * Name: Axmad
*/
#include <vector>
#include <iostream>

class TagGame {
public:
    TagGame(int n, int x) : n(n), x(x) {
        adj.resize(n);
        depth.resize(n);
    }

    void addEdge(int a, int b) {
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    int playGame() {
        dfs(0, -1, 0);
        int aliceMoves = depth[x - 1] - 1;

        if (aliceMoves % 2 == 0) {
            return n;
        } else {
            for (int i = 0; i < n; i++) {
                if (depth[i] == depth[x - 1] / 2 && adj[i].size() == 1) {
                    return 1;
                }
            }
            return n - 1;
        }
    }

private:
    int n, x;
    std::vector<std::vector<int>> adj;
    std::vector<int> depth;

    void dfs(int v, int p, int d) {
        depth[v] = d;

        for (int u : adj[v]) {
            if (u != p) {
                dfs(u, v, d + 1);
            }
        }
    }
};
