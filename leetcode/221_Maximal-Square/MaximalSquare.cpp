#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        if (cols == 0) return 0;
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int val = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = (matrix[i][j] == '1') ? 1 : 0;
                } else if (matrix[i][j] == '1') {
                    if (dp[i-1][j-1]) {
                        dp[i][j] = (dp[i-1][j] && dp[i][j-1]) ? min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j])+1 : 1;
                    } else {
                        dp[i][j] = 1;
                    }
                } else {
                    dp[i][j] = 0;
                }
                val = max(val, dp[i][j]);
            }
        }
        return val * val;      
    }
};