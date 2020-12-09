#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        if (n <= 0) return 0;
        int m = haystack.size();
        if (m < n) return -1;
        for (int i = 0; i <= m-n; ++i) {
            if (haystack.substr(i, n) == needle) {
                return i;
            }
        }
        return -1;
    }
};