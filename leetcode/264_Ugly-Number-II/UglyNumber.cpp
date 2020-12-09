#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> dp(n, 0);
        if (n == 1) return 1;
        dp[0] = 1;
        int a = 0, b = 0, c = 0;
        for (int i = 1; i < n; ++i) {
            // long long min_v = INT_MAX;
            // for (int j = 0; j < i; ++j) {
            //     if (dp[j] * 2 > dp[i-1]) {
            //         min_v = min(min_v, dp[j] * 2);
            //         break;
            //     }
            //     if (dp[j] * 3 > dp[i-1]) {
            //         min_v = min(min_v, dp[j] * 3);
            //         continue;
            //     }
            //     if (dp[j] * 5 > dp[i-1]) {
            //         min_v = min(min_v, dp[j] * 5);
            //     }
            // }
            // dp[i] = min_v;
            dp[i] = min(dp[a]*2, min(dp[b]*3, dp[c]*5));
            if (dp[i] == dp[a] * 2) ++a;
            if (dp[i] == dp[b] * 3) ++b;
            if (dp[i] == dp[c] * 5) ++c; 
        } 
        return dp[n-1];
    }
};