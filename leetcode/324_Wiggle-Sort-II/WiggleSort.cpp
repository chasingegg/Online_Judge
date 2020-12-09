#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        int n = nums.size();
        sort(tmp.begin(), tmp.end());
        int i = (n-1) / 2;
        int j = n - 1;
        int k = 0;
        while (k < n) {
            if (k & 1) {
                nums[k++] = tmp[j--];
            } else {
                nums[k++] = tmp[i--];
            }
        }
    }
};