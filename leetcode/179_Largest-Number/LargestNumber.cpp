#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
	static bool compare(int i, int j) {
		return (to_string(i)+to_string(j)) > (to_string(j)+to_string(i));
	}
	string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string res;
        for (int i = 0; i < nums.size(); ++i) {
        	res += to_string(nums[i]);
        }
        if (res.size() <= 1 || res[0] != '0') {
        	return res;
        }
        int pos = 0;
        for (int i = 1; i < res.size(); ++i) {
        	if (res[i] != '0' ) 
        		break;
        	pos++;
        }
        return res.substr(pos);
    }
};