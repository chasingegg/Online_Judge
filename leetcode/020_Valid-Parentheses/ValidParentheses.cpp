#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n == 0) return true;
        stack<char> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (!st.empty()) {
                    char t = st.top();
                    if (!((t == '[' && s[i] == ']') || (t == '{'
                         && s[i] == '}') || (t == '(' && s[i] == ')')) ) {
                        return false;
                    }
                    st.pop();
                } else {
                    return false;
                }
            }

        }
        return st.empty();
    }
};