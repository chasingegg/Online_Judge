#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
    int minDistance(string word1, string word2) {
        vector< vector<int> > d(word1.length()+1, vector<int>(word2.length()+1, 0));

        for (int i = 0; i < word1.length()+1; ++i) {
            for (int j = 0; j < word2.length()+1; ++j) {
                if (i == 0) {
                    d[i][j] = j;
                } else if (j == 0) {
                    d[i][j] = i;
                }
            }
        }

        for (int i = 1; i < word1.length()+1; ++i) {
            for (int j = 1; j < word2.length()+1; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    d[i][j] = d[i-1][j-1];
                } else {
                    d[i][j]= 1 + min(d[i-1][j-1], min(d[i-1][j], d[i][j-1]));
                }
            }
        }        
        return d[word1.length()][word2.length()];
    }  
};