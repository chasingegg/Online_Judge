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
    int pathSum(TreeNode *root, int sum, bool consecutive) {
        int result = 0;
        if (root) {
            if (sum == root->val) {
                result += 1;
            }
            result += pathSum(root->left, sum - root->val, true) +
                      pathSum(root->right, sum - root->val, true);
            if (!consecutive) {
                result += pathSum(root->left, sum, false) +
                          pathSum(root->right, sum, false);
            }
        }
        return result;
    }

    int pathSum(TreeNode* root, int sum) {
        return pathSum(root, sum, false);
    }
};