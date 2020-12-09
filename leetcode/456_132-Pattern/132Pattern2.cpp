#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int prev = -2147400000;
        for (auto it = nums.rbegin(); it != nums.rend(); it++) {
            while (!s.empty() && s.top() < (*it)) {
                if (prev > s.top()) return true;
                prev = s.top();
                s.pop();
            }
            s.push(*it);  
        }      
        return !s.empty() && prev > s.top();
    }
};