#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // counting sort
    string mysort(string str) {
        int s[26] = {0};
        int n = str.length();
        string res;
        for (int i = 0; i < n; ++i) {
            s[str[i]-'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < s[i]; ++j) {
                res.push_back('a' + i);
            }
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> res;
        for (int i = 0; i < n; ++i) {
            string tmp = mysort(strs[i]);
            if (res.find(tmp) != res.end()) {
                res[tmp].push_back(strs[i]);
            } else {
                vector<string> tt(1, strs[i]);
                res.insert(make_pair(tmp, tt));
            }
        }
        vector<vector<string>> ans;
        for (auto iter = res.begin(); iter != res.end(); iter++) {
            ans.push_back(iter->second);
        }
        return ans;
     }
};