#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string compose(string s, int& index) {
        string temp = "";  // 存放结果
        int num = 0;
        for (; index < s.size() && s[index] != ']'; ++index) {
            if (s[index] >= '0' && s[index] <= '9') {
                num = num * 10 + s[index] - '0';
            } else if (s[index] == '[') {
                string part = compose(s, ++index);
                for (int i = 0; i < num; ++i) {
                    temp += part;
                }
                num = 0;
            } else {
                num = 0;
                temp += s[index];
            }
        }
        return temp;
    }

    string decodeString(string s) {
        if (s.empty()) return s;
        int index = 0;
        return compose(s, index);
    }
};