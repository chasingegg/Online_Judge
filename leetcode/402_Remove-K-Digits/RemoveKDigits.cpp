#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMinIndex(string &num, int s, int len) {
        int minIdx = s;
        for (int i = s + 1; i <= num.size() - len; ++i) {
            if (num[i] < num[minIdx]) minIdx = i;
            if (num[minIdx] == '0') break;
        }
        return minIdx;
    }

    string removeKdigits(string num, int k) {
        string ans;
        int minIdx;
        int n = num.size();
        if (n == 0) return ans;
        if (n == k) return "0";
        minIdx = -1;
        // 想法很简单，就找n-k个最小的数
        for (int i = n-k; i >= 1; --i) {
            minIdx = findMinIndex(num, minIdx+1, i);
            if (ans.size() == 0 && num[minIdx] == '0' ) {
                continue;
            }
            ans += num[minIdx];
        }
        return ans.size() == 0 ? "0":ans;
    }
};