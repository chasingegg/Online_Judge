#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0) return false;
        int last = 0;
        for (int i = 0; i < len; ++i) {
            if (last >= i) {
                last = max(i + nums[i], last);
                if (last >= len -1) break;
            }
        }
        return last >= len -1;
    }
};