#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *pre = NULL;

    void inorder(TreeNode *root) {
        if (root == NULL) return;
        inorder(root -> left);
        if (pre == NULL) {
            pre = root;
        } else {
            if (pre -> val > root -> val) {
                if (first == NULL) first = pre;
                second = root;
            } 
            pre = root;
        }
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first -> val, second -> val);
    }
};