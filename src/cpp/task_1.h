/*
 * Author: Axmad Xurshetov
 * Date: 31.10.2023
 * Name: Axmad
 */

#include <vector>
#include <deque>
#include <iostream>

class ShortestPath {
public:
    ShortestPath(int n, int m, int k) : n(n), m(m), k(k) {
        graph.resize(n + 1);
        shortestDistance.assign(n + 1, -1);
        previousCity.resize(n + 1);
        visited.assign(n + 1, false);
        forbiddenTriplets.resize(k);
    }

    void addRoad(int x, int y) {
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    void addForbiddenTriplet(int a, int b, int c) {
        forbiddenTriplets.push_back({a, b, c});
    }

    void findShortestPath() {
        std::deque<int> q;
        q.push_back(1);
        shortestDistance[1] = 0;
        visited[1] = true;

        while (!q.empty()) {
            int currentCity = q.front();
            q.pop_front();

            for (int nextCity : graph[currentCity]) {
                if (!visited[nextCity]) {
                    shortestDistance[nextCity] = shortestDistance[currentCity] + 1;
                    previousCity[nextCity] = currentCity;
                    visited[nextCity] = true;
                    q.push_back(nextCity);
                }
            }
        }

        if (shortestDistance[n] == -1) {
            return;
        }

        int currentCity = n;
        std::vector<int> path;

        while (currentCity != 1) {
            path.push_back(currentCity);
            currentCity = previousCity[currentCity];
        }

        path.push_back(1);
        std::reverse(path.begin(), path.end());

        for (int i = 0; i < k; ++i) {
            if (shortestDistance[forbiddenTriplets[i][0]] != -1 &&
                shortestDistance[forbiddenTriplets[i][1]] != -1 &&
                shortestDistance[forbiddenTriplets[i][2]] != -1) {
                for (int j = 0; j < path.size() - 2; ++j) {
                    if ((path[j] == forbiddenTriplets[i][0] && path[j + 1] == forbiddenTriplets[i][1] && path[j + 2] == forbiddenTriplets[i][2]) ||
                        (path[j] == forbiddenTriplets[i][2] && path[j + 1] == forbiddenTriplets[i][1] && path[j + 2] == forbiddenTriplets[i][0])) {
                        std::cout << path.size() << std::endl;
                        for (int city : path) {
                            std::cout << city << " ";
                        }
                        return;
                    }
                }
            }
        }

        std::cout << path.size() << std::endl;
        for (int city : path) {
            std::cout << city << " ";
        }
    }

    int getShortestDistance() const {
        return shortestDistance[n];
    }

    std::vector<int> getShortestPath() const {
        int currentCity = n;
        std::vector<int> path;

        while (currentCity != 1) {
            path.push_back(currentCity);
            currentCity = previousCity[currentCity];
        }

        path.push_back(1);
        std::reverse(path begin(), path.end());

        return path;
    }

private:
    int n, m, k;
    std::vector<std::vector<int>> graph;
    std::vector<int> shortestDistance;
    std::vector<int> previousCity;
    std::vector<bool> visited;
    std::vector<std::vector<int>> forbiddenTriplets;
};
