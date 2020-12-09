#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return 0;
        // sort(nums.begin(), nums.end());
        // int res = 1;
        // int tmp = 1;
        // for (int i = 0; i < n-1; ++i) {
        //     if (nums[i+1] - nums[i] != 1 && nums[i+1] != nums[i]) {
        //         res = max(res, tmp);
        //         tmp = 1;
        //     } else if (nums[i+1] == nums[i]) {
        //         continue;
        //     } else {
        //         tmp++;
        //     }
        // }
        // return max(res, tmp);
        unordered_map<int, bool> map;
        for (auto num : nums) {
            map[num] = true;
        }
        int res = 1;
        for (auto num : map) {
            if (map.find(num.first-1) == map.end()) {
                int cur = num.first;
                int cur_res = 1;
                while (map.find(cur+1) != map.end()) {
                    cur++;
                    cur_res++;
                }
                res = max(cur_res, res);
            }
        }
        return res;
    }
};