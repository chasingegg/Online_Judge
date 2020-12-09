#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int i = atoi(s.c_str());
        if (s[0] == '0') {
            return s == "0";
        }
        if (i < 256 && i > 0) {
            return true;
        } else {
            return false;
        }
    }
    void dfs(string s, string temp, vector<string> &res, int count) {
        if (count == 3 && isValid(s)) {
            res.push_back(temp + s);
            return;
        }
        for (int i = 1; i < 4 && i < s.length(); ++i) {
            string substring = s.substr(0, i);
            if (isValid(substring)) {
                dfs(s.substr(i), temp + substring + ".", res, count +1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() < 4 || s.length() > 12) return res;
        dfs(s, "", res, 0);
        return res;
    }
};