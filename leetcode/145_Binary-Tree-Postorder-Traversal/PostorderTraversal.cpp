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
    void post(TreeNode *root, vector<int>& res) {
        if (root == NULL) return;
        post(root -> left, res);
        post(root -> right, res);
        res.push_back(root -> val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        post(root, res);
        return res;    
    }
};