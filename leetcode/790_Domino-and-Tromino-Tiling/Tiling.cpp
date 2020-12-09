#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTilings(int N) {
        vector<long> dp(N+1, 0);
        int M = 1e9 + 7;
        if (N == 1) return 1;
        if (N == 2) return 2;
        if (N == 3) return 5;
        dp[0] = 1; dp[1] = 1;
        dp[2] = 2; dp[3] = 5;
        for (int i = 4; i <= N; ++i) {
            dp[i] = (2 * dp[i-1] + dp[i-3]) % M;
        }
        return dp[N];
    }
};