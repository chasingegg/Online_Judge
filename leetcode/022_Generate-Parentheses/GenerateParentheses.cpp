#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> ans;

    void dfs(string tmp, int left, int right, int n) {
        if (left + right == 2*n) {
            ans.push_back(tmp);
        }
        if (left < n) {
            dfs(tmp + "(", left + 1, right, n);
        }
        if (left > right) {
            dfs(tmp + ")", left, right+1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs("", 0, 0, n);
        return ans;
    }
};