#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode *root, int &prev, int &count, int &cur_max, vector<int> &maxs) {
        if (root == nullptr) {
            return;
        }
        dfs(root -> left, prev, count, cur_max, maxs);
        if (root -> val == prev) {
            count++;
        } else {
            prev = root -> val;
            count = 1;
        }
        if (count >= cur_max) {
            if (count > cur_max) {
                cur_max = count;
                maxs.clear();
            }
            maxs.push_back(root -> val);
        }
        dfs(root -> right, prev, count, cur_max, maxs);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        int prev = 0;
        int count = 0;
        int cur_max = 0;
        dfs(root, prev, count, cur_max, modes);
        return modes;
    }
};