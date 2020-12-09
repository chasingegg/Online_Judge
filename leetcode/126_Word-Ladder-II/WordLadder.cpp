#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    bool oneword(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        int res = 0;
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) {
                ++res;
                if (res > 1) return false;
            }
        }
        return res == 1;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        queue<vector<string>> que;
        unordered_set<string> visit;
        unordered_set<string> wordlist(wordList.begin(), wordList.end());
        que.push(vector<string>{beginWord});
        int i;
        for (i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord) {
                break;
            }
        }
        if (i == wordList.size()) return res;
        while (!que.empty()) {
            int f = 0;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                vector<string> now = que.front();
                que.pop();
                if (oneword(now[now.size()-1], endWord)) { // 假如就差一步
                    f = 1; // 已经找到最优结果的flag
                    now.push_back(endWord);
                    res.push_back(now);
                }
                for (auto x : wordlist) {
                    if (oneword(x, now[now.size()-1])) {
                        now.push_back(x);
                        que.push(now);
                        now.erase(now.end()-1);
                        visit.insert(x);
                    }
                } 
            } // 每一层的数据处理完毕
            for(auto it=visit.begin();it!=visit.end();it++) 
                wordlist.erase(*it);
            visit.clear();
            if (f) {
                break;
            }
        }
        return res;
    }   
};