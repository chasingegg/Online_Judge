#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        for (int i = 1; i <= num; ++i) {
            dp[i] = dp[i / 2] + (i & 1);
        }
        return dp;
    }
};