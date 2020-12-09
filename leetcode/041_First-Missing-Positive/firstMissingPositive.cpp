#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
    public:
        int firstMissingPositive(vector<int> nums) {
            int size = nums.size();
            int positive = 0;
            for(int i = 0; i < size; i++){
                if(nums[i] > 0){
                    positive = nums[i];
                    break;
                } 
            }
            if(positive == 0) return 1;
            for(int i = 0; i < size; i++) {
                if(nums[i] <= 0) nums[i] = positive;
            }

            for (int i = 0; i < size; ++i) {
                int tmp  = abs(nums[i]);
                if (tmp < size + 1 && tmp > 0 && nums[tmp-1] > 0) {
                    nums[tmp-1] = -nums[tmp-1];
                }
            }

            for (int i = 0; i < size; ++i) {
                if (nums[i] >= 0) return i + 1;
            }
            return size + 1;
        }
};