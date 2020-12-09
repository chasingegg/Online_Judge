#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPa(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right; 
        }
        return true;
    }

    void dfs(vector<vector<string>>& res,  vector<string>& tmp, int start, string s) {
        if (start == s.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (isPa(s, start, i)) {
                string x = s.substr(start, i+1-start);
                tmp.push_back(x);
                dfs(res, tmp, i+1, s);
                tmp.erase(tmp.end()-1); // backtracking
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        int n = s.size();
        if (n <= 0) return res;
        dfs(res, tmp, 0, s);
        return res;
    }
};