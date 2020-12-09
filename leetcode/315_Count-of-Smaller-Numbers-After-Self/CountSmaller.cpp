#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            int counter = 0;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] < nums[i]) ++counter;
            }
            res[i] = counter;
        }
        return res;
    }
};