#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {    
        if (S < 0) S = (-1) * S;
        vector<vector<int>> dp(nums.size(), vector<int>(3000, 0));
        if (nums.size() == 0) {
            return 0;
        }
        dp[0][nums[0]] = (nums[0] == 0) ? 2 : 1;
        int sum = 0;
        for(int& x : nums) sum += x;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j <= sum; ++j) {
                dp[i][j] = dp[i-1][abs(j-nums[i])] + dp[i-1][j+nums[i]];               
            }
        }   
        return (S <= sum) ? dp[nums.size()-1][S]:0;
    }
};