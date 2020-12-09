#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 1) return false;
        if (k == 0) {
            int f = 0;
            for (int i = 0; i < len - 1; ++i) {
                if (nums[i] == 0 && nums[i+1] == 0) {
                    f = 1;
                    return true;
                }
            }
            if (!f) {
                return false;
            }
        }
        if (k < 0) {
            k = (-1) * k;
        }
        set<int> ss;
        ss.insert(nums[0]%k);
        for (int i = 1; i < len; ++i) {
            if (ss.count((k-nums[i]%k)%k)) {
                return true;
            }
            vector<int> tmp(ss.begin(), ss.end());
            ss.clear();
            for (auto &sss : tmp) {
                ss.insert((sss + nums[i]) % k);
            }
            ss.insert(nums[i] % k);
        }
        return false;
    }
};