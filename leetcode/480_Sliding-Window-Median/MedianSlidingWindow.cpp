#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        int n = nums.size();
        if (n == 0)
            return result;

        multiset<double> max, min;
        for (int i = 0; i < k; ++i)
            max.insert(nums[i]);

        for (int i = 0; i < k/2; ++i) {
            min.insert(*max.rbegin());  
            // 删除 第一个大于等于某个键的迭代器，如果没有就删除末端元素
            max.erase(max.lower_bound(*max.rbegin()));
        }

        for (int i = k; i < n; ++i) {
            if(k % 2 )
                result.push_back(*max.rbegin());
            else
                result.push_back((*max.rbegin() + *min.begin()) / 2);
            if (max.find(nums[i-k]) != max.end()) {
                max.erase(max.find(nums[i-k]));
                max.insert(nums[i]);
            } else {
                min.erase(min.find(nums[i-k]));
                min.insert(nums[i]);
            }
            if (max.size() > 0 && min.size() > 0 && *max.rbegin() > *min.begin()) {
                int tmp = *max.rbegin();
                max.erase(max.lower_bound(*max.rbegin()));
                max.insert(*min.begin());
                min.erase(min.begin());
                min.insert(tmp);
            }
        }
        if(k % 2 )
            result.push_back(*max.rbegin());
        else
            result.push_back((*max.rbegin() + *min.begin()) / 2);

        return result;
    }
};