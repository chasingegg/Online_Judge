#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int solve(string s, int l, int r, int k) {
        if (r - l < k) return 0; 
        unordered_map<char, int> a;
        for (int i = l; i < r; ++i) {
            a[s[i]]++;
        }
        int start = l;
        int ret = 0;
        // 
        for (int i = l; i < r; ++i) {
            if (a[s[i]] < k) {
                ret = max(ret, solve(s, start, i, k));
                start = i+1;
            }
        }
        // 每个元素个数都大于k
        if (start == l) {
            return r - l;
        }
        return max(ret, solve(s, start, r, k));
    }

    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size(), k);
    }
};