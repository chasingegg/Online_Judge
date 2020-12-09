#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res;
        stack<int> s;
        if (T.size() <= 0) return res;
        for (int i = T.size()-1; i >= 0; --i) {
            // 栈里的元素都小的话，不停弹出
            while (!s.empty() && T[s.top()] <= T[i]) {
                s.pop();
            }
            int wt = s.empty() ? 0 : s.top() - i;
            res.push_back(wt);
            s.push(i);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};