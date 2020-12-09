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
    void inorder(TreeNode *root, vector<int> &res) {
        if (root == NULL) return;
        inorder(root -> left, res);
        res.push_back(root -> val);
        inorder(root -> right, res);
    } 

    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        vector<int> res;
        inorder(root, res);
        int n = res.size();
        for (int i = 0; i < n-1; ++i) {
            if (res[i] >= res[i+1]) return false;
        }
        return true;
    }
};