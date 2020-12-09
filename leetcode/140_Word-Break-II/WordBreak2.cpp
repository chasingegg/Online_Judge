#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<string> > cache;
    vector<string> FindWord(string s, set<string> &wordDict) {
        if (cache.count(s)) {
            return cache[s];
        }
        vector<string> res;
        if (s.size() == 0) {
            res.push_back("");
            return res;
        }
        for (auto word : wordDict) {
            if ( s.length() >= word.length() && s.compare(0, word.length(), word) == 0) {
                vector<string> tail = FindWord(s.substr(word.length()), wordDict);
                for (auto t : tail) {
                    res.push_back(word + (t.empty() ? "" : " ") + t);
                }
            }
        }
        cache[s] = res;
        return res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> ss(wordDict.begin(), wordDict.end());
        return FindWord(s, ss);
    }   
};