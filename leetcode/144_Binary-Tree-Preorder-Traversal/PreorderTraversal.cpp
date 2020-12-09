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
    void pre(TreeNode *root , vector<int>& res) {
        if (root == NULL) return;
        res.push_back(root -> val);
        pre(root -> left, res);
        pre(root -> right, res);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        pre(root, res);
        return res;
    }
};