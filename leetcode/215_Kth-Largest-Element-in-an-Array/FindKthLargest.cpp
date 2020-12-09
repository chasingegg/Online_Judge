#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 0) return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; ++i) {
            if (i < k) {
                pq.push(nums[i]);
            } else {
                if (nums[i] > pq.top()) {
                    pq.push(nums[i]);
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};