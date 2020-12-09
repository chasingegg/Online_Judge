#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        if (nums[0] == k) dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            int res = 0;
            for (int j = i; j >= 0; --j) {
                res += nums[j];
                if (res == k) dp[i]++;
            }
            dp[i] += dp[i-1];
        }
        return dp[n-1];
    }
};