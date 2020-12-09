#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // int n = nums.size();
        // if (n == 0) return 0;
        // vector<int> dp(n, 0);
        // if (nums[0] < k) dp[0] = 1;
        // for (int i = 1; i < n; ++i) {
        //     long res = 1;
        //     for (int j = i; j >= 0; --j) {
        //         res *= nums[j];
        //         if (res < k) dp[i]++;
        //     }
        //     dp[i] += dp[i-1];
        // }
        // return dp[n-1];
        int counter = 0;
        if (k <= 1) return counter;
        int i1 = 0;
        int prod = 1;
        for (int i2 = 0; i2 < nums.size(); ++i2) {
            prod *= nums[i2];
            while (prod >= k) {
                prod /= nums[i1];
                ++i1;
            }
            counter += i2 - i1 + 1;
        }
        return counter;
    }
};