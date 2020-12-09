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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = 0;
        if (root -> left != nullptr && root -> left -> left == nullptr && root -> left -> right == nullptr) res += root -> left -> val;
        return res + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};