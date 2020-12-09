#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

class Solution {
public:
	bool is_reach(vector<int> &nums, int m, long target_num) {
		long cur_sum = nums[0];
		int section = 1;
		for (int i = 1; i < nums.size(); ++i) {
			cur_sum += nums[i];
			if (cur_sum > target_num) {
				++section;
				cur_sum = nums[i];
			}
		}
		if (section > m) return false;
		return true;
	}

	int splitArray(vector<int>& nums, int m) {
		int n = nums.size();
		long low = nums[0], high = nums[0];
		for (int i = 1; i < n; ++i) {
			low = max(low, long(nums[i]));
			high += nums[i];
		}
		while (low < high) {
			long mid = (low + high) / 2;
			if (is_reach(nums, m, mid)) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		return low;
	}
};