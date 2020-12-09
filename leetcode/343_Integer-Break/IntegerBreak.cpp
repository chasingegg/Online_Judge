#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i/2; ++j) {
                int t1 = max(j, dp[j]);
                int t2 = max(i-j, dp[i-j]);
                dp[i] = max(dp[i], t1 * t2);
            } 
        }
        return dp[n];
    }
};