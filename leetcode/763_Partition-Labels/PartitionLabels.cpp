#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int ffind(int start, int end, string S) {
        int i = start;
        int f = start;
        char s = S[i];
        while (i <= end) {
            if (S[i] == s) {
                f = i;
            }
            ++i;
        }
        if (f == end) return end;
        for (i = start+1; i <= f; ++i) {
            int j = f+1;
            while (j <= end) {
                if (S[j] == S[i]) {
                    f = j;
                }
                ++j;
            }
            if (f == end) return end;
        }
        return f;
    }

    vector<int> partitionLabels(string S) {
        int start = 0;
        int end = S.size() - 1;
        int tmp = 0;
        vector<int> res; 
        if (end <= 0) return res;
        while (start <= end) {
            tmp = ffind(start, end, S);
            res.push_back(tmp-start+1);
            start = tmp + 1;
        }
        return res;
    }
};