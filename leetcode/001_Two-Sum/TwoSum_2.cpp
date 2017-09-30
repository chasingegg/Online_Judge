/*
Date: 2017.8.14
Author: Chao Gao
Lang: C++
*/

//it is a great chance to learn C++ STL

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hashtable;
        for(int i = 0; i < nums.size(); ++i) {
            if(!hashtable.count(nums[i]))
                hashtable.insert(pair<int, int>(nums[i], i));
            if(hashtable.count(target - nums[i])) {
                int j = hashtable[target - nums[i]];
                if(j != i) {
                    res.push_back(j);
                    res.push_back(i);
                    return res;
                }
            }
        }
    }
};