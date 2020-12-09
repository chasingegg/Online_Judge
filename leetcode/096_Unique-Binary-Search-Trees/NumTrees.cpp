#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int num) {
        if (num == 0) return 0;
        vector<int> dp(num+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= num; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[num];
    }
};