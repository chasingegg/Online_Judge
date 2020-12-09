#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (n == 0 || n == k) return "0";
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            int digit = num[i] - '0';
            if (st.empty() || digit > st.top()) {
                st.push(digit);
            } else {
                while (k > 0 && (!st.empty() && st.top()>digit)) {
                    st.pop();
                    k--;
                }
                st.push(digit);
            }
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        string str;
        while (!st.empty()) {
            str += to_string(st.top());
            st.pop();
        }
        reverse(str.begin(), str.end());
        int index = 0;
        while (index < str.size() && str[index] == '0') index++;
        return index >= str.size() ? "0" : str.substr(index);
    }
};