#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool judge(string s, set<string>& ss) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (ss.count(s.substr(j, i-j))) {
                    if (j != 0 && !dp[j]) continue;
                    dp[i] = dp[j] + 1;
                } 
                if (dp[i] >= 2) break;
            }
        }
        return dp[n] >= 2;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        set<string> ss(words.begin(), words.end());
        vector<string> res;
        for (auto word : words) {
            if (judge(word, ss)) {
                res.push_back(word);
            }
        }
        return res;
    }

};