#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> judge;
        set<string> res;
        if (s.size() < 10) {
            return vector<string>(res.begin(), res.end());
        }
        for (int i = 9; i < s.size(); ++i) {
            string tmp = s.substr(i-9, 10);
            if (judge.count(tmp)) {
                res.insert(tmp);
            } else {
                judge.insert(tmp);
            }

        }
        return vector<string>(res.begin(), res.end());
    }
};
