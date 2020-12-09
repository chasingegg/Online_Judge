#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int fr[128] = {0};
        int k = s1.size();
        int n = s2.size();
        if (k > n) return false;
        for (int i = 0; i < k; ++i) {
            ++fr[s1[i]];
        }
        int cnt = k;
        int i = 0;
        int j = 0;
        while (i < n) {
            if (fr[s2[i]] > 0) {
                --cnt;
                --fr[s2[i]];
                ++i;
            } else {
                ++cnt;
                ++fr[s2[j]];
                ++j;
            }
            if (cnt == 0 && (i - j) == k) {
                return true;
            }
        }
        return false;
    }
};