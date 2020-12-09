#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        if (n != popped.size()) return false;
        if (n == 0) return true;
        stack<int> st;
        int cur = 0;
        for (auto x : pushed) {
            st.push(x);
            while (!st.empty() && cur < n && st.top() == popped[cur]) {
                st.pop();
                ++cur;
            }
        }
        return cur == n;
    }
};