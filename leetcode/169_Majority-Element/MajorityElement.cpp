#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return 0;
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};