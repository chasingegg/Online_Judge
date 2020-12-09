#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

class Solution {
public:
	// int会overflow leetcode上直接过不去
	unsigned long long max(unsigned long long a1, unsigned long long a2) {
		return a1 > a2 ? a1 : a2;
	}
	unsigned long long min(unsigned long long a1, unsigned long long a2) {
		return a1 < a2 ? a1 : a2;
	}
    int splitArray(vector<int>& nums, int m) {
    	int n = nums.size();
    	if (n <= 0) {
    		return 0;
    	}
        vector<vector<unsigned long long> > dp(n+1, vector<unsigned long long>(m+1, 2147483647));
        vector<int> help(n+1);
        // dp[n][m]表示前n个数分成m组，每组和的最大值的最小值
        for (int i = 1; i <= n; ++i) {
        	dp[i][0] = 2147483647;
        }
        for (int j = 0; j <= m; ++j) {
        	dp[0][j] = 0;
        }
        dp[1][1] = nums[0];
        for (int i = 1; i <= n; ++i) {
        	for (int j = 1; j <= min(m, i); ++j) {
        		unsigned long long tmp = 0;
        		for (int k = i; k > 0; --k) {
        			help[k] = (tmp = tmp + nums[k-1]);
        			dp[i][j] = min(dp[i][j], max(dp[k-1][j-1], help[k]));
        		}
        	}
        }
        return dp[n][m];
    }
};