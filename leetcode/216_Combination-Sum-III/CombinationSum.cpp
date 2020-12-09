#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> dfs(int k, int idx, int target) {
        if (target == 0 && k == 0) return vector<vector<int>>(1);
        vector<vector<int>> res;
        for (int i = idx; i < 10; ++i) {
            if (idx > target) break;
            vector<vector<int>> tmp = dfs(k-1, i+1, target-i);
            if (tmp.size() != 0) {
                for (auto t : tmp) {
                    t.push_back(i);
                    res.push_back(t);
                }
            }
        }
        return res;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (n > 45 || k <= 0) return res;
        res = dfs(k, 1, n);
        return res;
    }
};