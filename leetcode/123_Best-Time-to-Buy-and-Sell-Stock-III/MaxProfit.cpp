#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n = 3;
        // int m = prices.size();
        // if (m <= 1) return 0;
        // vector<vector<int>> dp(3, vector<int>(m, 0));
        // for(int i = 1; i < n; i++){
        //     int max_tmp = 0;
        //     for(int j = 1; j < m; j++) {
        //         int k = j - 1;
        //         while(k >= 0) {
        //             int diff = prices[j] - prices[k] + dp[i-1][k];
        //             max_tmp = max(diff, max_tmp);
        //             k--;
        //         }
        //         dp[i][j] = max(max_tmp,dp[i][j-1]);
                
        //     }
        // }
        // return dp[n-1][m-1];
        int n = prices.size();
        if (n <= 1) return 0;
        int bought1 = -1 * prices[0];
        int sold1 = 0;
        int bought2 = INT_MIN;
        int sold2 = 0;

        for(int i = 1; i < n; i++) {
            bought1 = max(bought1, -1 * prices[i]);
            sold1 = max(sold1, bought1 + prices[i]);
            bought2 = max(bought2, sold1 - prices[i]);
            sold2 = max(sold2, bought2 + prices[i]);
        }

        return sold2;
    }
};