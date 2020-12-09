#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return dfs(candidates, 0, target);
    }

    vector<vector<int>> dfs(vector<int>& candidates, int idx, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        if (target == 0) return vector<vector<int>>(1);
        for (int i = idx; i < n; ++i) {
            if (candidates[i] > target) break;
            if (i != idx && candidates[i-1] == candidates[i]) continue;
            vector<vector<int>> tmp = dfs(candidates, i+1, target-candidates[i]);
            // cout << tmp.size();
            if (tmp.size() != 0) {
                for (auto t : tmp) {
                    t.push_back(candidates[i]);
                    res.push_back(t);
                }
            }
        }
        return res;
    }
};