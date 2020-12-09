#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n-1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = i == j ? 1 : 1 + dp[i+1][j];
                for (int k = i+1; k <= j; ++k) {
                    if (s[k] == s[i]) {
                        dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k][j]); 
                    }
                }
            }
        }
        return (n == 0) ? 0 : dp[0][n - 1];
    }
};