#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        if (n <= 1) return n;
        dp[0] = 0; dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int min_v = INT_MAX;
            for (int j = (int)(sqrt(i)); j >= 1; --j) {
                min_v = min(min_v, dp[i-j*j]);  
            }
            dp[i] = min_v + 1;
        }
        return dp[n];
    }
};