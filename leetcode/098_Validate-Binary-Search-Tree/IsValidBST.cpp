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
    bool valid(TreeNode *root, long lower, long upper) {
        if (root == NULL) return true;
        if (lower != 2147483648 && root -> val <= lower) return false;
        if (upper != 2147483648 && root -> val >= upper) return false;
        if (!(valid(root -> right, root -> val, upper))) return false;
        if (!(valid(root -> left, lower, root -> val))) return false;
        return true;
    }

    bool isValidBST(TreeNode* root) {
        return valid(root, long(2147483648), long(2147483648));
    }
};