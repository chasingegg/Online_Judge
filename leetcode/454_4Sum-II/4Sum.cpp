#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> map;
        int counter = 0;
        for (auto a : A) {
            for (auto b : B) {
                int tmp = a + b;
                if (map.find(tmp) == map.end()) {
                    map[tmp] = 1;
                } else {
                    map[tmp]++;
                }
            }
        }
        for (auto c : C) {
            for (auto d : D) {
                int tmp = - (c + d);
                if (map.find(tmp) != map.end()) {
                    counter += map[tmp];
                }
            }
        }
        return counter;
    }
};