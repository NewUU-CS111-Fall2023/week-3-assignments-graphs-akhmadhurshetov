/*
 * Author: Axmad Xurshetov
 * Date: 31.10.2023
 * Name: Axmad
 */
#include <vector>
#include <string>
#include <iostream>

class Spikies {
public:
    Spikies(int n, int m, int j) : n(n), m(m), j(j), maze(n, std::vector<char>(m)) {}
    
    void readMaze() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cin >> maze[i][j];
            }
        }
    }
    
    std::string solveMaze() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (maze[i][j] == '@') {
                    return canEscape(i, j, j) ? "SUCCESS" : "IMPOSSIBLE";
                }
            }
        }
        return "IMPOSSIBLE";
    }

private:
    int n, m, j;
    std::vector<std::vector<char>> maze;
    
    bool canEscape(int x, int y, int spikesLeft) {
        if (x < 0 || x >= n || y < 0 || y >= m) {
            return false;
        }
        char tile = maze[x][y];
        if (tile == 'x') {
            return true;
        } else if (tile == '#' || tile == 's' || (tile == 'x' && spikesLeft < 1)) {
            return false;
        }

        bool result = false;
        if (tile == '@') {
            if (spikesLeft > 0) {
                spikesLeft--;
            } else {
                return false;
            }
        }

        maze[x][y] = '#';  // Mark visited tile as a wall

        result = canEscape(x + 1, y, spikesLeft) || canEscape(x - 1, y, spikesLeft) ||
                 canEscape(x, y + 1, spikesLeft) || canEscape(x, y - 1, spikesLeft);

        maze[x][y] = '.';  // Restore tile after exploration

        return result;
    }
};

#endif
