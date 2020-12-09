#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int front = 0;
        int end = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++front;
            } else if (s[i] == ')') {
                ++end;
                if (end > front) return false;
            }
        }
        return front == end;
    }

    int longestValidParentheses(string s) {
        if (s.size() == 0) return 0;
        int res = 0;
        // for (int i = 0; i < s.size(); ++i) {
        //     for (int j = 2; j <= s.size()-i; j += 2) {
        //         if (isValid(s.substr(i, j))) {
        //             res = max(res, j);
        //         }
        //     }
        // }
        // return res;
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '(') dp[i] = 0;
            else {
                if (s[i] == ')' && s[i-1] == '(') {
                    dp[i] = (i > 2) ? dp[i-2]+2 : 2;
                }
                if (s[i] == ')' && s[i-1] == ')') {
                    if (i - dp[i-1] >= 1 && s[i-dp[i-1]-1] == '(')
                    dp[i] = dp[i-1] + (i - dp[i-1] >= 2?dp[i - dp[i-1] - 2]:0) + 2;
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};