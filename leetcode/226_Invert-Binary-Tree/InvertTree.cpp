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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode *tmp1 = invertTree(root -> right);
        TreeNode *tmp2 = invertTree(root -> left);
        root -> left = tmp1;
        root -> right = tmp2;
        return root;
    }
};