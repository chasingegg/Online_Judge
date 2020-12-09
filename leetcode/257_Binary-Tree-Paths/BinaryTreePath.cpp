#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void gen(TreeNode *root, string s, vector<string> & res) {
        if (root == NULL) return;
        // 叶子
        if (root -> left == NULL && root -> right == NULL) {
            s += to_string(root -> val);
            res.push_back(s);
            return;
        }
        s += to_string(root -> val) + "->";
        gen(root -> left, s, res);
        gen(root -> right, s, res);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        gen(root, "", res);
        return res;
    }
};