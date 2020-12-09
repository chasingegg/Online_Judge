#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(11, 0);
        dp[0] = 1;
        dp[1] = 10;
        for(int i = 2; i <= 10 && i<=n; i++) {
            dp[i] = (dp[i-1]-dp[i-2])*(10-i+1) + dp[i-1];
        }
        return n>10 ? dp[10] : dp[n];
    }
};