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
    void inorder(TreeNode *root, vector<TreeNode *>& list, vector<int>& values) {
        if (root == NULL) return;
        inorder(root -> left, list, values);
        list.push_back(root);
        values.push_back(root -> val);
        inorder(root -> right, list, values);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode *> list;
        vector<int> values;
        inorder(root, list, values);
        sort(values.begin(), values.end());
        for (int i = 0; i < values.size(); ++i) {
            list[i] -> val = values[i];
        }
    }
};