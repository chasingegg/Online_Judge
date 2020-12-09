#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dfs(vector<int>& nums, int index, int val) {
        if (index == nums.size()-1) {
            if (nums[index] == 0 && val == 0) {
                return 2;
            } 
            if (nums[index] == val || nums[index] == (-1)*val) {
                return 1;
            } else {
                return 0;
            }
        }
        return dfs(nums, index+1, val+nums[index]) + dfs(nums, index+1, val-nums[index]);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums, 0, S);
    }
};