#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> res;
        for (int i = 0; i < n-3; ++i) {
            for (int j = i+1; j < n-2; ++j) {
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    int sum = nums[i]+nums[j]+nums[k]+nums[l];
                    if (sum == target) {
                        res.insert(vector<int>{nums[i],nums[j],nums[k],nums[l]});
                        k++; --l;
                    } else if (sum < target) {
                        ++k;
                    } else {
                        --l;
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};