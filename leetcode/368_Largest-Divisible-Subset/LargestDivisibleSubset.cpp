#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return nums;
        vector<int> dp(n, 1);
        vector<int> pre(n, -1);
        int index = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0 && dp[j]+1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
            if (dp[index] < dp[i]) {
                index = i;
            }
        }
        vector<int> res;
        while (index != -1) {
            res.push_back(nums[index]);
            index = pre[index];
        }     
        reverse(res.begin(), res.end());
        return res;
    }
};