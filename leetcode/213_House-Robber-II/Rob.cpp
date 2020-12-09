#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int Find(vector<int>& nums, int start, int end) {
        int n = nums.size();
        vector<int> dp(end-start+2,  0);
        dp[0] = 0;
        dp[1] = nums[start];
        for (int i = start+2; i <= end+1; ++i) {
            dp[i-start] = max(dp[i-start-1], dp[i-start-2]+nums[i-1]);
        }
        return dp[end-start+1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return max(Find(nums, 0, n-2), Find(nums, 1, n-1));
    }
};