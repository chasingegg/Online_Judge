#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> Find(vector<int>& nums, int n) {
        vector<vector<int>> res;
        vector<int> null;
        res.push_back(null);
        if (n == 0) return res;
        vector<vector<int>> pre = Find(nums, n-1);
        res = pre;
        for (auto p : pre) {
            p.push_back(nums[n-1]);
            res.push_back(p);
        }
        return res;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        return Find(nums, nums.size());
    }
};