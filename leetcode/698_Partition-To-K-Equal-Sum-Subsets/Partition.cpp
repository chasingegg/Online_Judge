#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<int>& nums, vector<bool>& flag, int target, int k, int start, int sum) {
        if (k == 1) return true;
        if (target == 0) return dfs(nums, flag, sum, k-1, 0, sum);
        for (int i = start; i < nums.size(); ++i) {
            if (!flag[i]) {
                flag[i] = true;
                if (dfs(nums, flag, target-nums[i], k, i+1, sum)) return true;
                flag[i] = false;
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        if (sum % k != 0 || n < k) return false;
        int target = sum / k;
        vector<bool> flag(n, false);
        return dfs(nums, flag, target, k, 0, target);
    }
};