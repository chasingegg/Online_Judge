#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (S < 0) {
            S = (-1)*S;
        }
        int sum = 0;
        for (auto& num : nums) {
            sum += num;
        }
        if (sum < S) return 0;
        if ((S + sum) % 2 != 0) return 0;
        int target = (S + sum) / 2;  // 接下来就是寻找和为target的组合
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (auto num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] += dp[i-num];
            }
        }
        return dp[target];
    }
};