#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        int cur = 0;
        int res = 1;
        for (int i = 1; i < n; ++i) {
            if ((cur > 0 && nums[i] > nums[i-1]) || (cur < 0 && nums[i] < nums[i-1]) || (nums[i] == nums[i-1]))
                continue;
            cur = nums[i] - nums[i-1];
            res++;
        }
        return res;
    }
};