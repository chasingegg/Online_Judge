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
    int cal(TreeNode *root, int &len) {
        if (root == NULL) return -1;
        int len1 = 0;
        int len2 = 0;
        int left_height = cal(root -> left, len1);
        int right_height = cal(root -> right, len2);
        len = max(max(left_height + right_height + 2, len1), len2);
        return left_height > right_height ? left_height + 1:right_height+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int len = 0;
        cal(root, len);
        return len;
    }
};