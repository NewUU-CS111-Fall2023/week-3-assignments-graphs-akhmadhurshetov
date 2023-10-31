/*
 * Author: Axmad Xurshetov
 * Date: 31.10.2023
 * Name: Axmad
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Genome {
public:
    Genome(int n) : n(n) {
        usedNucleotides.clear();
        fragmentMap.clear();
    }

    void addFragment(const std::string& fragment) {
        if (!fragment.empty()) {
            char firstNucleotide = fragment[0];
            fragmentMap[firstNucleotide].push_back(fragment);
            usedNucleotides[firstNucleotide] = false;
        }
    }

    std::string restoreGenome() {
        std::string genome;
        genome.clear();

        char startingNucleotide = 'a';
        while (fragmentMap.find(startingNucleotide) == fragmentMap.end()) {
            startingNucleotide++;
        }

        dfs(startingNucleotide, genome);

        return genome;
    }

private:
    int n;
    std::unordered_map<char, bool> usedNucleotides;
    std::unordered_map<char, std::vector<std::string>> fragmentMap;

    void dfs(char currentNucleotide, std::string& currentGenome) {
        if (usedNucleotides[currentNucleotide]) {
            return;
        }

        usedNucleotides[currentNucleotide] = true;

        for (const std::string& fragment : fragmentMap[currentNucleotide]) {
            if (fragment[0] == currentNucleotide) {
                currentGenome += fragment;
                int fragmentLen = fragment.length();

                char nextNucleotide = fragment[fragmentLen - 1];
                dfs(nextNucleotide, currentGenome);
            } else {
                currentGenome = fragment + currentGenome;
                int fragmentLen = fragment.length();

                char nextNucleotide = fragment[0];
                dfs(nextNucleotide, currentGenome);
            }
        }
    }
};
