#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        if (n <= 0) return res;
        res[0] = 1;
        for (int i = 1; i < n; ++i) {
            res[i] = res[i-1] * nums[i-1];
        }
        int R = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] = res[i] * R;
            R *= nums[i];
        }
        return res;
    }
};