#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
private:
	unordered_map<int, set<int>> tag;  // 保存每个元素对应的index编号集合

public:
    Solution(vector<int> nums) {
        for (int i = 0; i < nums.size(); ++i) {
        		tag[nums[i]].insert(i);
        }
        srand((int)time(0));
    }
    
    int pick(int target) {
        if (tag.find(target) == tag.end()) {
        	return 0;
        }
        int res = 0;
        int size = tag[target].size();
        int cnt = 1;
        for (set<int>::iterator it = tag[target].begin(); it != tag[target].end(); it++) {
        	if (rand() % (cnt++) == 0) {
        		res = *it;
        	}
        } 
        return res;
    }
};