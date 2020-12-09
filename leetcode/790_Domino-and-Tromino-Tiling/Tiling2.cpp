#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTilings(int N) {
        vector<vector<long> > dp(N+1, vector<long>(2, 0));
        int M = 1e9 + 7;
        if (N == 1) return 1;
        if (N == 2) return 2;
        if (N == 3) return 5;
        // for (auto dd : dp) {
        //     for (auto d : dd) {
        //         cout << d << " ";
        //     }
        //     cout << endl;
        // }
        dp[1][0] = 1;
        dp[1][1] = 0;
        dp[2][0] = 2;
        dp[2][1] = 2;
        for (int i = 3; i <= N; ++i) {
            dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-2][0]) % M;
            dp[i][1] = (dp[i-1][1] + dp[i-2][0] * 2) % M; 
        }
        return dp[N][0];
    }
};