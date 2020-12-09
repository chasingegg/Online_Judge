#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int Find(vector<int>& nums, int start, int end, int target) {
        if (start > end) {
            return -1;
        }
        if (start == end && nums[start] != target) {
            return -1;
        }
        if (start == end && nums[start] == target) {
            return start;
        }
        if (end - start == 1) {
            if(target == nums[start]) {
                return start;
            } else if (target == nums[end]) {
                return end;
            }
        }
        int mid = start + (end-start)/2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > nums[start] && nums[mid] < nums[end]) {
            if (target < nums[mid]) {
                return Find(nums, start, mid-1, target);
            } else {
                return Find(nums, mid+1, end, target);
            }
        }
        if (nums[mid] < nums[start] && nums[mid] < nums[end]) {
            if (target < nums[mid]) {
                return Find(nums, start, mid-1, target);
            } else if (target > nums[mid] && target <= nums[end]) {
                return Find(nums, mid+1, end, target);
            } else if (target > nums[mid] && target > nums[end]) {
                return Find(nums, start, mid-1, target);
            }
        }
        if (nums[mid] > nums[start] && nums[mid] > nums[end]) {
            if (target > nums[mid]) {
                return Find(nums, mid+1, end, target);
            } else if (target < nums[start]) {
                return Find(nums, mid+1, end, target);
            } else if (target >= nums[start]) {
                return Find(nums, start, mid-1, target);
            }

        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        return Find(nums, 0, nums.size()-1, target);    
    }
};