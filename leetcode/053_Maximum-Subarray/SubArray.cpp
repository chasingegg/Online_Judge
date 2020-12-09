#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return 0;
        int cur = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; ++i) {
            // 要么是nums[i]，要么是前面的和+nums[i]，表示用到num[i]的最大和
            cur = max(nums[i], cur + nums[i]);
            res = max(res, cur);
        }
        return res;
    }
};