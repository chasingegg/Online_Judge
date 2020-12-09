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
    void dfs(TreeNode *root, int &level, int cur_level, int &value) {
        if (root == nullptr) return;
        if (cur_level > level && root -> left == nullptr && root -> right == nullptr) {
            value = root -> val;
            level = cur_level;
        }
        dfs(root -> left, level, cur_level+1, value);
        dfs(root -> right, level, cur_level+1, value);
    }

    int findBottomLeftValue(TreeNode* root) {
        int level = 0;
        int value = 0;
        dfs(root, level, 1, value);
        return value;
    }
};