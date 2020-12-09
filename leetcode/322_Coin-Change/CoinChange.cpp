#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;  // leetcode上这个情况是要返回0。。。
        }
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (auto coin : coins) {
                if (i >= coin) {
                    if (dp[i-coin] != INT_MAX || i-coin == 0) 
                        dp[i] = min(dp[i], dp[i-coin]+1);
                } else {
                    break;
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];  
    }
};