#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPai(string s) {
        for (int i = 0; i < s.size()/2; ++i) {
            if (s[i] != s[s.size()-1-i]) {
                return false;
            }
        }
        return true;
    }
    int minCut(string s) {
        int len = s.size();
        vector<vector<bool>> table(len, vector<bool>(len, false));
        for (int r = 0; r < len; ++r) {
            for (int l = r; l >= 0; --l) {
                if (r - l == 0 || (s[r] == s[l] && r - l == 1)) {
                    table[l][r] = true;
                } else {
                    table[l][r] = table[l+1][r-1] && (s[l] == s[r]);
                }
            }
        }

        vector<int> dp(len+1, INT_MAX);
        dp[0] = -1;
        for (int r = 1; r <= s.length(); ++r) {
            for (int l = r; l > 0; --l) {
                if (table[l-1][r-1]) {
                    dp[r] = min(dp[r], dp[l-1]+1);
                }
            }
        }

        return dp.back();
    }
};