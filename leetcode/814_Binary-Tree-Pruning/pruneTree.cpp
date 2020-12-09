#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *cal(TreeNode *root) {
        if (root == NULL) return root;
        TreeNode *left = cal(root -> left);
        TreeNode *right = cal(root -> right);
        root -> left = left;
        root -> right = right;
        if (!left && !right) {
            return root -> val == 0 ? NULL : root;
        }
        return root;
    }

    TreeNode* pruneTree(TreeNode* root) {
        return cal(root);

    }
};