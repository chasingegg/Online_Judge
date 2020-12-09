#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        vector<int> minV(n, 0);
        minV[0] = nums[0];
        for (int i = 1; i < n-1; ++i) {
            minV[i] = min(minV[i-1], nums[i]); 
        }    
        for (int i = n-1; i >= 1; --i) {
            if (minV[i-1] == nums[i-1]) continue;
            int MAx = -2147400000;
            for (int j = i; j < n; ++j) {
                if (nums[j] < nums[i-1] && nums[j] > minV[i-1]) {
                    return true;
                } 
            }
        }
        return false;
    }
};