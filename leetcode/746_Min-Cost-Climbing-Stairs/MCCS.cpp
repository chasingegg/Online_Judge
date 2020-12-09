#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> dp(len, 0);
        if (len == 0) return 0;
        if (len == 1) return cost[0];
        if (len == 2) return cost[1] > cost[0] ? cost[0] : cost[1];
        dp[0] = cost[0]; dp[1] = cost[1];
        for (int i = 2; i < len; ++i) {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }   
        return dp[len-1] > dp[len-2] ? dp[len-2] : dp[len-1];
    }
};
