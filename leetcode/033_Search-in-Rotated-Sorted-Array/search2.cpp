#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1;
        
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (target == nums[mid])
                return mid;
            if (nums[left] <= nums[mid]) {  // 4 5 7 1 3 or 1 2 3 4 5
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid -1;
                } else {
                    left = mid + 1;
                }
            } else {  // 4 5 1 2 3 关键就是小于等于中的等于
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid +1;
                } else {
                    right = mid -1;
                }
            }
        }
        return -1;
    }
};