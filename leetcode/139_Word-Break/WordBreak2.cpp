#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> ss(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] = dp[j] & ss.count(s.substr(j,i-j));
                if (dp[i]) break;
            }
        }
        return dp[n];
    }
};