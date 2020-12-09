#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int> > res;
         sort(nums.begin(), nums.end());
         if (nums.size() < 3) return res;
         for (int i = 0; i < nums.size()-2; ++i) {
             int fix = nums[i];
             if (fix > 0) break;
             if (i > 0 && fix == nums[i-1]) {
                 continue;
             } 
             fix = fix * (-1);
             int s = i + 1; int t = nums.size()-1;
             while (s < t) {
                 if (nums[s] + nums[t] == fix) {
                     res.push_back({(-1)*fix, nums[s], nums[t]});
                     while (s < t && nums[s] == nums[s+1]) ++s;
                     ++s; --t;
                 } else if (nums[s] + nums[t] < fix) {
                     ++s;   
                 } else {
                     --t;
                 }
             }
         }
         return res;

    }
};