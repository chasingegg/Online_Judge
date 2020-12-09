#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<char, vector<string> > map;

    vector<string> LetterCombinations(string digits, unordered_map<char, vector<string>> &map) {
        vector<string> res;
        if (digits.size() == 0) return res;
        if (digits.size() == 1) {
            return map[digits[0]];
        }   
        res = LetterCombinations(digits.substr(1), map);
        vector<string> rr;
        for (string x : map[digits[0]]) {
            for (auto r : res) {
                rr.push_back(x + r);
            }

        }
        return rr;  
    }

    vector<string> letterCombinations(string digits) {
        map['2'] = vector<string>{"a", "b", "c"};
        map['3'] = vector<string>{"d", "e", "f"};
        map['4'] = vector<string>{"g", "h", "i"};
        map['5'] = vector<string>{"j", "k", "l"};
        map['6'] = vector<string>{"m", "n", "o"};
        map['7'] = vector<string>{"p", "q", "r", "s"};
        map['8'] = vector<string>{"t", "u", "v"};
        map['9'] = vector<string>{"w", "x", "y", "z"};
        return LetterCombinations(digits, map);
    }
};