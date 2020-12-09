#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() == 0) {
            return false;
        }
        int sm = accumulate(nums.begin(), nums.end(), 0);
        if (sm % 4 != 0) {
            return false;
        }
        int edge = sm/4;
        sort(nums.rbegin(), nums.rend());  // 倒序排列
        vector<int>lengths(4, edge);
         
        return dfs(nums, 0, lengths, -1);
    }

    bool dfs(vector<int>& nums, int k, vector<int>& lengths, int lastI) {
        if (k == nums.size()) {
            return true;
        }
        int start = (k > 0 && nums[k] == nums[k-1]) ? lastI : 0;
        for (int i = start; i < lengths.size(); i++) {
            if (i > 0 && lengths[i] == lengths[i-1]) {
                continue;
            }
            if (lengths[i] - nums[k] >= 0) {
                lengths[i] -= nums[k];
                if (dfs(nums, k+1, lengths, i)) {
                    return true;
                }
                lengths[i] += nums[k];
            }
        }
        return false;
    }
};