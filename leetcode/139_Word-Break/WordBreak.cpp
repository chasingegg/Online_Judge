#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    unordered_map<int, bool> cache; 
    bool word(string s, int x, set<string>& wordDict) {
        if (cache.count(x)) {
            return cache[x];
        }
        for (int i = s.size()-1; i >= x; --i) {
            if (wordDict.count(s.substr(x, i-x+1))) {
                if (s.size()-1 == i) {
                    cache[x] = true;
                    return true;                    
                }
                if (word(s, i+1, wordDict)) {
                    cache[x] = true;
                    return true;
                }
            }
        }
        cache[x] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> ss(wordDict.begin(), wordDict.end());
        // copy(wordDict.begin(), wordDict.end(), ss.begin());
        return word(s, 0, ss);
    }
};