/*
Date: 2017.8.17
Author: Chao Gao
Lang: C++
*/

//神之蔑视
//仔细一想这是对的 因为对于这个多个i来说肯定有一次最长的是到i这个尾巴的

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}