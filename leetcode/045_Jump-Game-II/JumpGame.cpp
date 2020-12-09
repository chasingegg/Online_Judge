#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return 0;

        int large = nums[0];
        int level = 1;
        int low = 1;
        if (large >= len-1) return level;
        ++level;
        int tmp = large;
        while (low <= large) {
            for (int i = low; i <= large && i < len; ++i) {
                if (nums[i]+i >= len-1) {
                    return level;
                } else if (nums[i]+i > tmp) {
                    tmp = nums[i]+i;
                }
            }
            low = large+1;
            large = tmp;
            ++level;
        }
        return level;
    }
};