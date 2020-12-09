#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool check(string num, string first, string second) {
        if (first.size() + second.size() >= num.size()) return false;
        if (first.size() > 1 && first[0] == '0') return false;
        if (second.size() > 1 && second[0] == '0') return false;
        int rel = first.size() + second.size();
        long result = stol(first) + stol(second);
        int result_size = (to_string(result)).size();
        if (num.size() < result_size + rel) return false;
        string cur = num.substr(rel, result_size);
        if (cur.size() > 1 && cur[0] == '0') return false;
        if (cur == to_string(result)) {
            if (num.size() == result_size + rel)
                return true;
            else
            return check(num.substr(first.size()), second, cur);
        }
        return false;
    }

    bool isAdditiveNumber(string num) {
        if (num.size() < 3) return false;
        // 两个for循环拆分前两段
        // 判断(num, first, second)
        for (int i = 1; i < num.size(); ++i) {
            string first = num.substr(0, i);
            for (int j = i; j < num.size(); ++j) {
                string second = num.substr(i, j-i+1);
                if (check(num, first, second)) return true;
            }
        }
        return false;
    }
};