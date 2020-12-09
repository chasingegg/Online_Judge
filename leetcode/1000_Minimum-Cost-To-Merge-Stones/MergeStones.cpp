#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n-1) % (K-1) > 0) return -1;
        vector<int> sum(n+1, 0); // 树状数组
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i-1] + stones[i-1];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int L = K; L <= n; ++L) {
            for (int i= 0, j=i+L-1; j < n; ++i, ++j) {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k += (K-1)) {
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
                }
                if ((L-1) % (K-1) == 0) {
                    dp[i][j] += sum[j+1] - sum[i];
                }
            }
        }
        return dp[0][n-1];
    }
};