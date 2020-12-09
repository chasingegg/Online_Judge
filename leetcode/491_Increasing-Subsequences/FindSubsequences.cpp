#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, vector<int>& vec, int begin) {
        unordered_set<int> s;  // 每次往后深搜 都是一个新的set
        for (int i = begin; i < nums.size(); ++i) {
            int n = vec.size();
            if (n == 0 || vec[n-1] <= nums[i]) {
                if (s.find(nums[i]) != s.end()) continue;
                vec.push_back(nums[i]);
                s.insert(nums[i]);
                if (vec.size() > 1) ans.push_back(vec);
                dfs(nums, vec, i+1);
                vec.pop_back(); // backtracking
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> vec;
        dfs(nums, vec, 0);
        return ans;
    }
};