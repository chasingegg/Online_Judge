#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void Swap(int &n, int &m) {
        int tmp = n;
        n = m;
        m = tmp;
    }
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            Swap(nums[start], nums[end]);
            start++; end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        if (k <= 0) return;
        int size = nums.size();
        k = k % size;
        reverse(nums, 0, size-k-1);
        reverse(nums, size-k, size-1);
        reverse(nums, 0, size-1);         
    }
};