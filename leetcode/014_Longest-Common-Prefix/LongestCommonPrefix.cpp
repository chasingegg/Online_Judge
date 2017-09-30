/*
Date: 2017.9.5
Author: Chao Gao
Lang: C++
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string res = "";
        if(n == 0) return res;
        
        int max_size = strs[0].length();
        for(int i = 0; i < max_size; ++i) {
            
            for(int j = 1; j < n; ++j) {
                if(i == strs[j].length() || strs[0][i] != strs[j][i])
                    return res;
            }
            res.push_back(strs[0][i]);
        }
        return res;
    }
};