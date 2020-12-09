#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() -1;
        while(left<right){
            int mid = left + (right-left)/2;
            int count = 0;
            for(int i= 0; i < nums.size();i++){
                if(nums[i]<=mid){
                    count+=1;
                }
            }
            if(count<=mid){
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};