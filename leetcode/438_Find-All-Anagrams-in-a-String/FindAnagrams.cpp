#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isEqual(string s, string p) {
        if (s.size() != p.size()) return false;
        sort(s.begin(), s.end());
        sort(p.begin(), p.end());
        return s == p;
    }

    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();
        vector<int> res;
        if (n < k) return res;
        // for (int i = 0; i <= n-k; ++i) {
        //     string tmp = s.substr(i, k);
        //     if (isEqual(tmp, p)) {
        //         res.push_back(i);
        //     }
        // }
        int fr[128] = {0};
        for (int i = 0; i < k; ++i) {
            ++fr[p[i]];
        }
        int i = 0; 
        int j = 0;
        int cnt = k;
        while (i < n) {
            if (fr[s[i]] > 0) {
                --cnt;
                --fr[s[i]];
                ++i;
            } else {
                ++fr[s[j]];
                ++cnt;
                ++j;
            }
            if (cnt == 0 && (i - j) == k) {
                res.push_back(j);
            }
        }
        return res;
    }
};