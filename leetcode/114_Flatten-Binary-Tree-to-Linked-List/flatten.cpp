#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* link(TreeNode *root) {
        if (root == NULL) return NULL;
        if (root -> left == NULL && root -> right == NULL) return root;
        if (root -> left == NULL && root -> right != NULL) {
            return link(root -> right);
        }
        if (root -> left != NULL && root -> right == NULL) {
            root -> right = root -> left;
            root -> left = NULL;
            return link(root -> right);
        }
        TreeNode* tail = link(root -> left);
        TreeNode* tmp = root -> right;
        root -> right = root -> left;
        root -> left = NULL;
        tail -> right = tmp;
        return link(tmp);
    }
    void flatten(TreeNode* root) {
        link(root);
    }
};