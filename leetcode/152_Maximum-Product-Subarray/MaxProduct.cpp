#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) {
        	return 0;
        }
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
        	int tmp = 1; int res = 0;
        	for (int j = i; j >= 0; --j) {
        		if ((tmp = tmp * nums[j]) > res) {
        			res = tmp;
        		}
        	}
        	dp[i] = (dp[i-1] > res) ? dp[i-1] : res;
        }
        return dp[n-1];
    }
};