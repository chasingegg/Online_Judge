#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int startPos = 0;
        int lastPos = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                startPos = mid;
                lastPos = mid;
                while (startPos > 0 && nums[startPos-1] == target) {
                    --startPos;
                }
                while (lastPos < n-1 && nums[lastPos+1] == target) {
                    ++lastPos;
                }
                return vector<int>{startPos, lastPos};
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        return vector<int>{-1, -1};
    }
};