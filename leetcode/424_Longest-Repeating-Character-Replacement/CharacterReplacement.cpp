#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(128, 0);
        int max_count = 0, lo = 0;
        for(int i = 0; i < s.size(); i++){
            // Current char is the only char the number changes, so we only need compare max count with current char count;
            max_count = max(max_count, ++count[s[i]]);
            // Whenever max_count + k > current window size, we expand current window: i++;
            // Otherwise, we shift current window forward by: lo-- and i++
            if(i - lo + 1 > max_count + k) count[s[lo++]]--;
        }
        return s.size() - lo;

    }
};