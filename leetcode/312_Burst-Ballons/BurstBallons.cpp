#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        dp[0][0] = 1;
        dp[n+1][n+1] = 1;
        for (int range = 0; range < n; ++range) {
            for (int i = 1; i <= n-range; ++i) {
                int j = i + range;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1]);
                }
            }
        }      
        return dp[1][n];
    }
};