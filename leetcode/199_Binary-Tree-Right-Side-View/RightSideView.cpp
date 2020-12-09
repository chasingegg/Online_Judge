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
    void dfs(TreeNode *root, vector<int>& res, int level) {
        if (root == NULL) return;
        if (level > res.size()) {
            res.push_back(root -> val);
        }
        dfs(root -> right, res, level + 1);
        dfs(root -> left, res, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        dfs(root, res, 1);
        return res;
    }
};