#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int left, int right, int n) {
        if (left > right) return -1;
        int mid = (left + right) / 2;
        if (mid < 1 || mid > right-1) return -1;
        if (nums[mid-1] < nums[mid] && nums[mid+1] < nums[mid]) {
            // cout << mid << endl;
            return mid;
        }
        return max((solve(nums, left, mid, n)), (solve(nums, mid+1, right, n)));
    }

    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int k = solve(nums, 0, n-1, n);
        if (k == -1) {
            if (nums[0] > nums[1]) return 0;
            else return n - 1;
        }
        return k;
    }
};