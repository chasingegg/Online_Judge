/*
Date: 2017.8.21
Author: Chao Gao
Lang: C++
*/

//dp来做
//dp[i][j]表示i,j这个区间的子串是否是回文子串

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int res = 0;
        int left = 0, right = 0;
        int dp[s.length()][s.length()];
        for(int i = 0; i < len; ++i) 
            for(int j = 0; j < len; ++j) 
                dp[i][j] = 0;

        for(int i = 0; i < len; ++i) {
            for(int j = 0; j < i; ++j) {
                if(s[i] == s[j] && (i - j < 2 || dp[j+1][i-1]))
                    dp[j][i] = 1;
                
                if(dp[j][i] && res < i - j + 1) {
                    res = i - j + 1;
                    left = j;
                    right = i;
                }
            }
            dp[i][i] = 1;
        }
        return s.substr(left, right - left + 1);
    }
};