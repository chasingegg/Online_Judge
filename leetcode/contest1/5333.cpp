#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (map1.count(s[i]) == 0) {
                map1[s[i]] = 1;
            } else {
                map1[s[i]]++;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (map2.count(t[i]) == 0) {
                map2[t[i]] = 1;
            } else {
                map2[t[i]]++;
            }
        }
        int res = 0;
        for (auto m : map1) {
            if (map2.count(m.first) > 0) {
                res += (map2[m.first] < m.second)? m.second-map2[m.first]:0;
            } else {
                res += m.second;
            }
        }
        return res;
    }
};

int main() {
    Solution so;
    string s = "leetcode";
    string t = "practice";
    cout << so.minSteps(s, t) << endl;
    return 0;
}
