#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void swap(int &t1, int &t2) {
        int tmp = t1;
        t1 = t2;
        t2 = tmp;
    }

    void sortColors(vector<int>& nums) {
        int zero = 0;
        int second = nums.size()-1;
        int i = 0;
        while (i <= second) {
            if (nums[i] == 0) {
                swap(nums[i], nums[zero]);
                zero++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[second]);
                second--;
            } else {
                i++;
            }
        }
    }
};