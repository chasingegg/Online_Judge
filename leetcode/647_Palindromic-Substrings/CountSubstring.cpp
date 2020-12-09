#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if (n <= 0) return 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (i == j) {
                    dp[j][i] = true;
                    ++res;
                } else if (i == j + 1) {
                    if (s[j] == s[i]) {
                        dp[j][i] = true;
                        ++res;
                    }
                } else if (i > j + 1) {
                    if (dp[j+1][i-1] && s[j] == s[i]) {
                        dp[j][i] = true;
                        ++res;
                    }
                }
            }
        }
        return res;
    }
};