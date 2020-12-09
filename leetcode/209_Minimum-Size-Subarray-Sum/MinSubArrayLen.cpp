#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size(); int min_res = INT_MAX;
        int sum = 0; int start = 0;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            while (sum >= s) {
                min_res = min(min_res, i - start + 1);
                sum -= nums[start++];
            }
        }
        return min_res == INT_MAX ? 0 : min_res;
    }
};