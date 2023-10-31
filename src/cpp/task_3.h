/*
 * Author: Axmad Xurshetov
 * Date: 31.10.2023
 * Name: Axmad
*/

#include <vector>
#include <iostream>

class Transformation {
public:
    Transformation(int a, int b) : a(a), b(b) {}

    void transformNumber() {
        std::vector<int> path;
        if (canTransform(a, path)) {
            std::cout << "YES" << std::endl;
            std::cout << path.size() << std::endl;
            for (int x : path) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

private:
    int a, b;

    bool canTransform(int x, std::vector<int>& path) {
        if (x == b) {
            path.push_back(x);
            return true;
        }

        if (x > b) {
            return false;
        }

        path.push_back(x);

        if (canTransform(x * 2, path)) {
            return true;
        }
        if (canTransform(x * 10 + 1, path)) {
            return true;
        }

        path.pop_back();
        return false;
    }
};
