#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        vector<string> res;
        if (len <= 0) return res;
        vector<int> tmp;

        for (int i = 0; i < len; ++i) {
            if (i == 0) {
                tmp.push_back(nums[i]);
            } else if (nums[i] == nums[i-1] + 1) {
                tmp.push_back(nums[i]);
            } else {
                if (tmp.size() > 1) {
                    res.push_back(to_string(tmp[0]) + "->" + to_string(tmp[tmp.size()-1]));
                } else {
                    res.push_back(to_string(tmp[0]));
                }
                tmp.clear();
                tmp.push_back(nums[i]);
            }
        } 
        if (tmp.size() > 1) {
            res.push_back(to_string(tmp[0]) + "->" + to_string(tmp[tmp.size()-1]));
        } else {
            res.push_back(to_string(tmp[0]));
        }
        return res;
    }
};