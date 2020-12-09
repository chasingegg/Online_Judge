#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (auto &str : strs) {
            int zeroes = count(str.begin(), str.end(), '0');
            int ones = str.size() - zeroes;
            for (int i = m; i >= 0; --i) {
                for (int j = n; j >= 0; --j) {
                    int current = (zeroes <= i && ones <= j) ? 1 + dp[i-zeroes][j-ones]:0;
                    dp[i][j] = max(dp[i][j], current);
                }
            }
        }
        return dp[m][n];
    }
};