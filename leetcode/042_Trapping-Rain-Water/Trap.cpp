#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 0) return 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int max_left = 0;
            int max_right = 0;
            for (int j = i; j >= 0; --j) {
                max_left = max(max_left, height[j]);
            }
            for (int j = i; j < n; ++j) {
                max_right = max(max_right, height[j]);
            }
            res += min(max_left, max_right) - height[i];
        }
        return res;
    }
};