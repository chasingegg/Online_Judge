#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:

    bool isValid(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') ++cnt;
            else if (s[i] == ')' && --cnt < 0) return false;
        }
        return cnt == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> visited; visited.insert(s);
        queue<string> que; que.push(s);
        bool found = false;
        while (!que.empty()) {
            string cur = que.front(); que.pop();
            if (isValid(cur)) {
                res.push_back(cur);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < cur.size(); ++i) {
                if (cur[i] != '(' && cur[i] != ')') continue;
                string s = cur.substr(0, i) + cur.substr(i+1);
                if (!visited.count(s)) {
                    visited.insert(s);
                    que.push(s);
                }
            }
        }
        return res;
    }
};