#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        if (sum % 2 == 1) return false;
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for (auto &num : nums) {
            for (int i = sum; i >= num; --i) {
                dp[i] = dp[i] || dp[i-num];
            }
        }
        return dp[sum/2];
    }
};