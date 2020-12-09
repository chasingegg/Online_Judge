#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        auto tmp = nums;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i, j;
        for (i = 0; i < n; ++i) {
            if (tmp[i] != nums[i]) break;
        }
        if (i == n) return 0;
        for (j = n-1; j >= 0; --j) {
            if (tmp[j] != nums[j]) break;
        }
        return j - i + 1;
    }
};