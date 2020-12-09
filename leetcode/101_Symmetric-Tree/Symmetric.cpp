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
    bool isEqual(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL) return true;
        if (left == NULL || right == NULL) return false;
        if (left -> val == right -> val) {
            if (isEqual(left -> left, right -> left) && 
                isEqual(left -> right, right -> right)) return true;;
        }
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isEqual(root -> left, root -> right);
    }
};