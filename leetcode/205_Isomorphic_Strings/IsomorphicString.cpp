#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> f1(256, 0);
        vector<int> f2(256, 0);
        for (int i = 0; i < s.size(); ++i) {
            if (f1[s[i]] == 0) {
                f1[s[i]] = t[i] + 1;
            } 
            if (f2[t[i]] == 0) {
                f2[t[i]] = s[i] + 1;
            }
            if (f1[s[i]] != 0 || f2[t[i]] != 0) {
                if (f1[s[i]] != t[i] + 1 || f2[t[i]] != s[i] + 1) return false;
            }
        }
        return true;
    }   
};