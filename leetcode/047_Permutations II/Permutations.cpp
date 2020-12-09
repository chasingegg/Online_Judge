#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void f(vector<vector<int> >&res, int pos, vector<int> &nums) {
        if (pos >= nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); ++i) {
            if (i > pos && nums[i] == nums[pos]) continue;
            swap(nums[i], nums[pos]);
            f(res, pos + 1, nums);
            // swap(nums[i], nums[pos]);
        }
        for (int i = nums.size() - 1; i > pos; --i) {
            swap(nums[pos], nums[i]);
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        f(res, 0, nums);
        return res;
    }
};