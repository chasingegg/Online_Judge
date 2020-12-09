#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int> > res = {{}};
       sort(nums.begin(), nums.end());
       int n = nums.size();
       int size = 0; int startIndex = 0;
       for (int i = 0; i < n; ++i) {
           startIndex = (i >= 1 && nums[i]==nums[i-1] ? size : 0);
           size = res.size();
           for (int j = startIndex; j < size; ++j) {
               vector<int> tmp = res[j];
               tmp.push_back(nums[i]);
               res.push_back(tmp);
           } 
       } 
       return res;
    }
};