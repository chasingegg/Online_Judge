#include <iostream>
#include <vector>
#include <string>
#include <cstring>
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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int i;
        int res = 1;
        for (i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord) {
                break;
            }
        }
        if (i == wordList.size()) return 0;
        for (i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == beginWord) {
                wordList.erase(wordList.begin() + i);
                break;
            }
        }
        queue<string> que;
        que.push(beginWord);
        while (!que.empty()) {
            vector<string> tmp;
            ++res;
            while (!que.empty()) {
                string word = que.front();
                que.pop();
                tmp.push_back(word);
            }
            for (auto t : tmp) {
                if (oneword(t, endWord)) {
                    return res;
                }
                int j = 0;
                for (;;) {
                    if (j == wordList.size()) break;
                    if (oneword(wordList[j], t)) {
                        que.push(wordList[j]);
                        wordList.erase(wordList.begin() + j);
                    } else
                        ++j;
                }
              
            }
            cout << endl;
        }
        return 0;
    }
};